#==========================================================================
#
#   Copyright Insight Software Consortium
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#          http://www.apache.org/licenses/LICENSE-2.0.txt
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#==========================================================================*/

#
# Verify that each class's PrintSelf prints all ivars that have
# a set/get.
#
#
# Verbose Levels:
#
#	0:	No extra printing
#	1:	Print basic extra information
#	2:	Print lots of details
#
set verbose 0

set class_name ""

set class_count 0
set class_print_count 0
set printself_miss_count 0
set super_miss_count 0
set ivar_count 0
set ivar_miss_count 0

set total_class_count 0
set total_class_print_count 0
set total_ivar_count 0
set total_printself_miss_count 0
set total_super_miss_count 0
set total_ivar_miss_count 0

# Fileid for the PrintSelfDetails.html file
set pd_id 0

#
# class_list contains the following for each class evaluated:
#
#  <class>.p		   <true|false> True if printself declared
#  <class>.s.<super_class> <true|false> True if superclass used in printself
#  <class>.i.<ivar>	   <true|false> True if ivar used in printself

set class_list(null) 1

proc list_contains { string } {

  global class_list

  set ivar_found 0
  set searchid [array startsearch class_list]

  while { [array anymore class_list $searchid] } {
    set element [array nextelement class_list $searchid]
    if { $element == $string } {
      set ivar_found 1
    }
  }

  array donesearch class_list $searchid

  return $ivar_found
}

proc get_ivar { string } {

  global verbose

  set ivar_string "-1"

#puts "Getting ivar from macro: $string"

  # Search for the first occurrence of an open parenthesis
  set first [string first "(" $string];

  if { $first > -1 } {

    set begintrim [string range $string [expr $first + 1] end];
    set begintrim [string trim $begintrim];

    # Find the end of the ivar
    set last [string wordend $begintrim 0]

    if { $last > -1 } {

      set ivar_string [string range $begintrim 0 [expr $last - 1] ];

      set ivar_string [string trim $ivar_string];

      if { $verbose >= 2 } {
        puts "    Macro: $ivar_string"
      }
    } 
  }

  return [string trim $ivar_string]
}

proc check_header_file { filename } {

  global class_name
  global class_count
  global ivar_count
  global class_list
  global verbose

  if { $verbose >= 2 } {
    puts "Processing file: $filename"
  }

  set data ""
  set class_name ""

  set printself_found 0
  set class_found 0

  if { [file readable $filename] } {
    set fileid [open $filename "r"]

    set private_not_found 1

    #
    # Read each line in the file
    #
    while { [gets $fileid data] >= 0 && $private_not_found } {

      # Search for the printSelf string
      if { [string match "*PrintSelf*(*" $data] == 1 } {
        set printself_found 1
        set class_list($class_name.p) 1
      }

      if { [string match "*private:*" $data] == 1 } {
        set private_not_found 0
      }

      # Search for the class string
      # Extract the class name from the string
      if { [string match "*class *_EXPORT*" $data] == 1 } {
          while { [gets $fileid rest] >= 0 && [string first "\{" $rest] == -1 } {
          lappend data $rest
          }
          set data [join $data]
        set class_found 1

        set class_ivar_count 0

        set first [string first "_EXPORT" $data];
        incr first 7
        if { $first > -1 } {

          set end [expr [string first ":" $data] - 1];

          set newstring [string range $data $first $end ]
          set class_name [string trim [string trimleft $newstring]];
        } 

        set class_list($class_name.p) 0

        if { $verbose >= 2 } {
          puts "    Class Name: $class_name"
        }

        set first [string first "public" $data]
        if { $first > -1 } {
          set first [expr $first + 7];
          set end [ string length $data]

          set string [string range $data $first $end ]

          set first [string first "itk" $string]
          set end [string wordend $string $first]

          set super_class [string range $string $first $end ]
          set super_class [string trim $super_class]

          set class_list($class_name.s.Superclass) 0
        }
      }

      if { $class_found == 1 } {

        # Search for Set and Get macros
        set set_macro_found [string match "*itkSet*Macro*(*" $data]
        set get_static_const_macro_found [string match "*itkGetStaticConstMacro*(*" $data]
        set get_macro_found [string match "*itkGet*Macro*(*" $data]

        if { !$get_static_const_macro_found && ( $set_macro_found || $get_macro_found  ) } {

          # Get the ivar from the Macro declaration
          set ivar [get_ivar $data];

          if { [string compare $ivar "-1"] != 0 } {
            if { [list_contains "$class_name.i.$ivar"] == 0 } {

              incr ivar_count
              incr class_ivar_count

              set class_list($class_name.i.$ivar) 0
            }
          }
        } 
      }
    } 

    # If a class was found within the file then increment the class count
    if { $class_found } {
      incr class_count
    }

    close $fileid

  }

}

proc check_printself { filename } {

  global verbose

  global class_list
  global class_name

  if { $verbose >= 2 } {
    puts "    Checking PrintSelf in file: $filename"
  }

  if { [file readable $filename] } {

    set fileid [open $filename "r"]

    set search_state 0

    set curly_open 0
    set curly_close 0

    set line_count 0

    #
    # Read each line in the file
    #
    while { [gets $fileid data] >= 0 && $search_state != 3 } {

      incr line_count

      # Search for the PrintSelf string
      if { $search_state == 0 && [string match "*PrintSelf*(*" $data] == 1 } {
        set search_state 1
        set first [string first ")" $data]
        set data [string range $data [expr $first + 1] end]
      }

      # Find the first open curly bracket
      if { $search_state == 1 } {
        while { [string length $data] > 0 && $curly_open == 0 } {
          # Check for an open curly bracket
          set curly_found [string first "\{" $data]
          if { $curly_found > -1 } {
            set data [string range $data [expr $curly_found + 1] end ]
            set curly_open 1
            set search_state 2
          } else {
            set data ""
          }
        }
      }

      # Count curly brackets in PrintSelf() method and find ivars
      if { $search_state == 2 } {

        set start 0
        set end [string length $data]
        if { [string match "*::PrintSelf(*)*" $data] == 1 } {
          set start [string first "itk" $data]
          set end [string wordend $data $start]

          set super_class [string range $data $start [expr $end -1]]
          set super_class [string trim $super_class]

          if { [list_contains "$class_name.s.Superclass"] == 1 } {
            set class_list($class_name.s.Superclass) 1
          } elseif { $verbose >= 2 } {
            puts "\tSuperclass Issue:\tCan't find $class_name.s.$super_class"
          }
        }

        while { $start < $end && $curly_open > $curly_close } {
          set word_end [string wordend $data $start]
          set token [string range $data $start [expr $word_end -1] ]
          set token [string trim $token]
          set start $word_end
	  if { $verbose >= 2 } {
	    puts "\tNew Token: $token"
	  }

          # Check for open and close curly braces
          if { [string compare "\{" $token] == 0 } {
            incr curly_open 
          } elseif { [string compare "\}" $token] == 0 } {
            incr curly_close
          } elseif { [string match m_* "$token"] == 1 } {
            set token_end [expr [string wordend $data $start ] - 1]
            set ivar [string range $token 2 end]
            set ivar [string trim $ivar]

            if { [list_contains "$class_name.i.$ivar"] == 1 } {
              set class_list($class_name.i.$ivar) 1
            } elseif { $verbose } {
              puts "\tIvar Issue:\t\tCan't find $class_name.i.$ivar"
            }
          } elseif { [string match Get* "$token"] == 1 } {
            set token_end [expr [string wordend $data $start ] - 1]
            set ivar [string range $token 3 end]
            set ivar [string trim $ivar]

            if { [list_contains "$class_name.i.$ivar"] == 1 } {
              set class_list($class_name.i.$ivar) 1
            } elseif { $verbose } {
              puts "\tIvar Issue:\t\tCan't find $class_name.i.$ivar"
            }
          } elseif { [string compare "this" $token] == 0 } {
            set start [expr $start + 2]
            set token_end [expr [string wordend $data $start ] - 1]
            set ivar [string range $data $start $token_end]
            if { [string first "Get" $ivar] > -1 } {
              set start [expr $start + 3];

              # Check if this is a Get*AsString() method
              if { [string first "AsString" $ivar] > -1 } {
                set token_end [expr $token_end - 8];
              }

              set ivar [string range $data $start $token_end]
            } 
            set ivar [string trim $ivar]

            if { [list_contains "$class_name.i.$ivar"] == 1 } {
              set class_list($class_name.i.$ivar) 1
            } elseif { $verbose } {
              puts "\tIvar Issue:\t\tCan't find $class_name.i.$ivar"
            }
          }
        }

        if { $curly_open == $curly_close } {
          set search_state 3
        }
      }
    }

    close $fileid
  }
}

proc read_directory { dirname } {

  global class_name
  global argv

  set total_defects 0

  set files [glob -nocomplain "$dirname/itk*.h"]

  if { $files != "" } {
    foreach headername $files {

      set class_name ""

      # Check that a PrintSelf() is defined
      check_header_file $headername

      # Check that the PrintSelf() method accesses the appropriate ivars 
      if { $class_name != "" && [list_contains "$class_name.p"] == 1 } {
        set length [string length $headername]
        set filename [string range $headername 0 [expr $length - 3] ]
        if {[file exists "$filename.txx"] == 1} {
          check_printself "$filename.txx"
        } elseif {[file exists "$filename.cxx"] == 1} {
          check_printself "$filename.cxx"
        } elseif {[file exists "$filename.h"] == 1} {
             check_printself "$filename.h" 
        }
      }

    }
  }
}

proc class_has_ivars { class } {

  global verbose
  global class_list

  set searchid [array startsearch class_list]

  while { [array anymore class_list $searchid] } {

    set element [array nextelement class_list $searchid]

    if { [string match "$class.i.*" $element] == 1 } {
      array donesearch class_list $searchid
      return 1
    }
  }

  array donesearch class_list $searchid

  return 0
}

proc check_for_defects { print } {

  global pd_id

  global verbose
  global class_list
  global class_print_count
  global ivar_miss_count
  global printself_miss_count
  global super_miss_count

  #
  #		PRINTSELF CHECK
  #

  # Loop through list and count printself defects, if any
  set searchid [array startsearch class_list]

  while { [array anymore class_list $searchid] } {

    set element [array nextelement class_list $searchid]
    # Extract strings that represent PrintSelfs
    if { [string match "*.p" $element] == 1 } {
      set end [expr [string wordend $element 0] - 1]
      set curr_class [string range $element 0 $end]

      if { [class_has_ivars $curr_class] == 1 } {

        incr class_print_count

        if { $class_list($element) != 1 } {

          incr printself_miss_count
        }
      }
    }
  }

  array donesearch class_list $searchid

  # Loop through list and print printself defects
  if { $printself_miss_count > 0 && $print } {
    puts $pd_id "  PrintSelf DEFECTS: "
    set searchid [array startsearch class_list]

    while { [array anymore class_list $searchid] } {

      set element [array nextelement class_list $searchid]
      # Extract strings that represent PrintSelfs
      if { [string match "*.p" $element] == 1 } {
        set end [expr [string wordend $element 0] - 1]
        set curr_class [string range $element 0 $end]

        if { [class_has_ivars $curr_class] == 1 } {
          if { $class_list($element) != 1 } {
            puts $pd_id "    $curr_class does not have a PrintSelf method"
          }
        }
      }
    }

    array donesearch class_list $searchid
  }

  #
  #		SUPERCLASS CHECK
  #

  # Loop through list and count superclass defects, if any
  set searchid [array startsearch class_list]

  while { [array anymore class_list $searchid] } {

    set element [array nextelement class_list $searchid]
    # Extract strings that represent superclasses
    if { [string match "*.s.*" $element] == 1 } {
      set end [expr [string wordend $element 0] - 1]
      set curr_class [string range $element 0 $end]

      if { [class_has_ivars $curr_class] == 1 &&
           $class_list($element) != 1 } {

        incr super_miss_count
      }
    }
  }

  array donesearch class_list $searchid

  # Loop through list and print superclass defects
  if { $super_miss_count > 0  && $print } {
    puts $pd_id "  Superclass DEFECTS: "
    set searchid [array startsearch class_list]

    while { [array anymore class_list $searchid] } {

      set element [array nextelement class_list $searchid]
      # Extract strings that represent superclasses
      if { [string match "*.s.*" $element] == 1 } {
        set end [expr [string wordend $element 0] - 1]
        set curr_class [string range $element 0 $end]

        if { [class_has_ivars $curr_class] == 1 &&
             $class_list($element) != 1 } {

            set start [expr $end + 4]
            set end [expr [string wordend $element $start] - 1]
            set parent [string range $element $start $end]

            puts $pd_id "    $curr_class did not print superclass"
        }
      }
    }

    array donesearch class_list $searchid
  }

  #
  #		IVAR CHECK
  #

  # Loop through list and count ivar defects, if any
  set searchid [array startsearch class_list]

  while { [array anymore class_list $searchid] } {

    set element [array nextelement class_list $searchid]

    # Extract strings that represent ivars
    if { [string match "*.i.*" $element] == 1 } {
      if { $class_list($element) != 1 } {
          incr ivar_miss_count

      }
    }
  }

  array donesearch class_list $searchid

  # Loop through list and print ivar defects
  if { $ivar_miss_count > 0 && $print } {
    puts $pd_id "  Ivar DEFECTS: "
    set searchid [array startsearch class_list]

    while { [array anymore class_list $searchid] } {

      set element [array nextelement class_list $searchid]

      # Extract strings that represent ivars
      if { [string match "*.i.*" $element] == 1 } {
        if { $class_list($element) != 1 } {
          set end [expr [string wordend $element 0] - 1]
          set curr_class [string range $element 0 $end]

          set start [expr $end + 4]
          set end [expr [string wordend $element $start] - 1]
          set ivar [string range $element $start $end]

          puts $pd_id "    $curr_class does not print ivar: m_$ivar"
        }
      }
    }

    array donesearch class_list $searchid
  }

}

proc print_toolkit_results { toolkit } {

  global pd_id

  global class_count
  global class_print_count
  global printself_miss_count
  global ivar_count
  global ivar_miss_count
  global super_miss_count

  check_for_defects 1

  set tk [string range $toolkit 0 14 ]

}

proc print_totals {} {
  global total_defects
  global total_class_count
  global total_class_print_count
  global total_printself_miss_count
  global total_ivar_count
  global total_ivar_miss_count
  global total_super_miss_count

  set total_defects [expr $total_printself_miss_count + $total_super_miss_count + $total_ivar_miss_count]

}

proc open_files { } {

  global pd_id

  set pd_id stdout

}

proc close_files { } {

  global pd_id

  close $pd_id

  set pd_id 0
}

proc clear_results { } {

  global class_count
  global class_print_count
  global printself_miss_count
  global ivar_count
  global ivar_miss_count
  global super_miss_count
  global class_list

  unset class_list
  set class_list(null) 1

  set class_count 0
  set class_print_count 0
  set ivar_count 0
  set printself_miss_count 0
  set ivar_miss_count 0
  set super_miss_count 0
}

proc measure_itk {kits} {

  global pd_id

  global verbose

  global class_list
  global class_count
  global class_print_count
  global printself_miss_count
  global ivar_count
  global ivar_miss_count
  global super_miss_count

  global total_class_count
  global total_class_print_count
  global total_printself_miss_count
  global total_ivar_count
  global total_ivar_miss_count
  global total_super_miss_count

  set path ""

  open_files

  foreach toolkit $kits {
    clear_results

    puts $pd_id " "
    puts $pd_id "Results for directory: $toolkit"

    read_directory $path$toolkit

    print_toolkit_results $toolkit

    set total_class_count [expr $total_class_count + $class_count]
    set total_class_print_count [expr $total_class_print_count + $class_print_count]
    set total_printself_miss_count [expr $total_printself_miss_count + $printself_miss_count];
    set total_ivar_count [expr $total_ivar_count + $ivar_count];
    set total_ivar_miss_count [expr $total_ivar_miss_count + $ivar_miss_count];
    set total_super_miss_count [expr $total_super_miss_count + $super_miss_count];
  }

  print_totals



  if { $verbose } {
    parray class_list
  }
  close_files
}
measure_itk [lindex $argv 0]

exit $total_defects
