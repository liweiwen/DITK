/*

This header file mangles all symbols exported from the v3p_netlib
library.  There are purposely no include blockers so translation units
can mangle/unmangle repeatedly.  It is included in all files while
building the library.

The following command was used to obtain the symbol list:

nm libv3p_netlib.a |grep " [TR] "

*/

/* Functions */

#define active_ v3p_netlib_active_
#define adaptquad_ v3p_netlib_adaptquad_
#define balanc_ v3p_netlib_balanc_
#define balbak_ v3p_netlib_balbak_
#define bmv_ v3p_netlib_bmv_
#define calcsc_ v3p_netlib_calcsc_
#define cauchy_ v3p_netlib_cauchy_
#define caxpy_ v3p_netlib_caxpy_
#define ccopy_ v3p_netlib_ccopy_
#define cdiv_ v3p_netlib_cdiv_
#define cdotc_ v3p_netlib_cdotc_
#define cg_ v3p_netlib_cg_
#define chscdf_ v3p_netlib_chscdf_
#define cmprlb_ v3p_netlib_cmprlb_
#define cqrdc_ v3p_netlib_cqrdc_
#define cqrsl_ v3p_netlib_cqrsl_
#define cscal_ v3p_netlib_cscal_
#define csrot_ v3p_netlib_csrot_
#define csvdc_ v3p_netlib_csvdc_
#define cswap_ v3p_netlib_cswap_
#define cub_ v3p_netlib_cub_
#define dasum_ v3p_netlib_dasum_
#define daxpy_ v3p_netlib_daxpy_
#define dcabs1_ v3p_netlib_dcabs1_
#define dchscdf_ v3p_netlib_dchscdf_
#define dcopy_ v3p_netlib_dcopy_
#define dcsrch_ v3p_netlib_dcsrch_
#define dcstep_ v3p_netlib_dcstep_
#define ddot_ v3p_netlib_ddot_
#define dgecon_ v3p_netlib_dgecon_
#define dgemm_ v3p_netlib_dgemm_
#define dgemv_ v3p_netlib_dgemv_
#define dgeqr2_ v3p_netlib_dgeqr2_
#define dgeqrf_ v3p_netlib_dgeqrf_
#define dger_ v3p_netlib_dger_
#define dgerq2_ v3p_netlib_dgerq2_
#define dgesc2_ v3p_netlib_dgesc2_
#define dgetc2_ v3p_netlib_dgetc2_
#define dggbak_ v3p_netlib_dggbak_
#define dggbal_ v3p_netlib_dggbal_
#define dgges_ v3p_netlib_dgges_
#define dgghrd_ v3p_netlib_dgghrd_
#define dgpfa2f_ v3p_netlib_dgpfa2f_
#define dgpfa3f_ v3p_netlib_dgpfa3f_
#define dgpfa5f_ v3p_netlib_dgpfa5f_
#define dgpfa_ v3p_netlib_dgpfa_
#define dhgeqz_ v3p_netlib_dhgeqz_
#define dlabad_ v3p_netlib_dlabad_
#define dlabax_ v3p_netlib_dlabax_
#define dlabcm_ v3p_netlib_dlabcm_
#define dlabfc_ v3p_netlib_dlabfc_
#define dlacon_ v3p_netlib_dlacon_
#define dlacpy_ v3p_netlib_dlacpy_
#define dladiv_ v3p_netlib_dladiv_
#define dlaeig_ v3p_netlib_dlaeig_
#define dlaev2_ v3p_netlib_dlaev2_
#define dlag2_ v3p_netlib_dlag2_
#define dlager_ v3p_netlib_dlager_
#define dlagv2_ v3p_netlib_dlagv2_
#define dlamc1_ v3p_netlib_dlamc1_
#define dlamc2_ v3p_netlib_dlamc2_
#define dlamc3_ v3p_netlib_dlamc3_
#define dlamc4_ v3p_netlib_dlamc4_
#define dlamc5_ v3p_netlib_dlamc5_
#define dlamch_ v3p_netlib_dlamch_
#define dlange_ v3p_netlib_dlange_
#define dlanhs_ v3p_netlib_dlanhs_
#define dlapy2_ v3p_netlib_dlapy2_
#define dlapy3_ v3p_netlib_dlapy3_
#define dlaran_ v3p_netlib_dlaran_
#define dlarf_ v3p_netlib_dlarf_
#define dlarfb_ v3p_netlib_dlarfb_
#define dlarfg_ v3p_netlib_dlarfg_
#define dlarft_ v3p_netlib_dlarft_
#define dlartg_ v3p_netlib_dlartg_
#define dlascl_ v3p_netlib_dlascl_
#define dlaset_ v3p_netlib_dlaset_
#define dlassq_ v3p_netlib_dlassq_
#define dlasv2_ v3p_netlib_dlasv2_
#define dlaswp_ v3p_netlib_dlaswp_
#define dlatdf_ v3p_netlib_dlatdf_
#define dlatrs_ v3p_netlib_dlatrs_
#define dmvpc_ v3p_netlib_dmvpc_
#define dnlaso_ v3p_netlib_dnlaso_
#define dnorcdf_ v3p_netlib_dnorcdf_
#define dnppla_ v3p_netlib_dnppla_
#define dnrm2_ v3p_netlib_dnrm2_
#define dnwla_ v3p_netlib_dnwla_
#define dorg2r_ v3p_netlib_dorg2r_
#define dorgqr_ v3p_netlib_dorgqr_
#define dorgr2_ v3p_netlib_dorgr2_
#define dorm2r_ v3p_netlib_dorm2r_
#define dormqr_ v3p_netlib_dormqr_
#define dormr2_ v3p_netlib_dormr2_
#define dortqr_ v3p_netlib_dortqr_
#define dpmeps_ v3p_netlib_dpmeps_
#define dpmpar_ v3p_netlib_dpmpar_
#define dpoco_ v3p_netlib_dpoco_
#define dpodi_ v3p_netlib_dpodi_
#define dpofa_ v3p_netlib_dpofa_
#define dposl_ v3p_netlib_dposl_
#define dqrdc_ v3p_netlib_dqrdc_
#define dqrsl_ v3p_netlib_dqrsl_
#define drot_ v3p_netlib_drot_
#define drotg_ v3p_netlib_drotg_
#define drscl_ v3p_netlib_drscl_
#define dscal_ v3p_netlib_dscal_
#define dspr_ v3p_netlib_dspr_
#define dsptrf_ v3p_netlib_dsptrf_
#define dsptrs_ v3p_netlib_dsptrs_
#define dsvdc_ v3p_netlib_dsvdc_
#define dswap_ v3p_netlib_dswap_
#define dtgex2_ v3p_netlib_dtgex2_
#define dtgexc_ v3p_netlib_dtgexc_
#define dtgsen_ v3p_netlib_dtgsen_
#define dtgsy2_ v3p_netlib_dtgsy2_
#define dtgsyl_ v3p_netlib_dtgsyl_
#define dtrmm_ v3p_netlib_dtrmm_
#define dtrmv_ v3p_netlib_dtrmv_
#define dtrsl_ v3p_netlib_dtrsl_
#define dtrsv_ v3p_netlib_dtrsv_
#define dvsort_ v3p_netlib_dvsort_
#define dzasum_ v3p_netlib_dzasum_
#define dznrm2_ v3p_netlib_dznrm2_
#define elmhes_ v3p_netlib_elmhes_
#define eltran_ v3p_netlib_eltran_
#define enorm_ v3p_netlib_enorm_
#define epslon_ v3p_netlib_epslon_
#define errclb_ v3p_netlib_errclb_
#define fd_ v3p_netlib_fd_
#define fdjac2_ v3p_netlib_fdjac2_
#define formk_ v3p_netlib_formk_
#define formt_ v3p_netlib_formt_
#define freev_ v3p_netlib_freev_
#define fv_ v3p_netlib_fv_
#define fvd_ v3p_netlib_fvd_
#define fxshfr_ v3p_netlib_fxshfr_
#define gpfa2f_ v3p_netlib_gpfa2f_
#define gpfa3f_ v3p_netlib_gpfa3f_
#define gpfa5f_ v3p_netlib_gpfa5f_
#define gpfa_ v3p_netlib_gpfa_
#define hpsolb_ v3p_netlib_hpsolb_
#define hqr2_ v3p_netlib_hqr2_
#define hqr_ v3p_netlib_hqr_
#define idamax_ v3p_netlib_idamax_
#define ieeeck_ v3p_netlib_ieeeck_
#define ilaenv_ v3p_netlib_ilaenv_
#define ins_ v3p_netlib_ins_
#define isamax_ v3p_netlib_isamax_
#define izamax_ v3p_netlib_izamax_
#define lb1_ v3p_netlib_lb1_
#define lbfgs_ v3p_netlib_lbfgs_
#define lce_ v3p_netlib_lce_
#define lde_ v3p_netlib_lde_
#define lmder1_ v3p_netlib_lmder1_
#define lmder_ v3p_netlib_lmder_
#define lmdif_ v3p_netlib_lmdif_
#define lmpar_ v3p_netlib_lmpar_
#define lnsrlb_ v3p_netlib_lnsrlb_
#define lsame_ v3p_netlib_lsame_
#define lse_ v3p_netlib_lse_
#define lsqr_ v3p_netlib_lsqr_
#define mainlb_ v3p_netlib_mainlb_
#define matupd_ v3p_netlib_matupd_
#define mcsrch_ v3p_netlib_mcsrch_
#define mcstep_ v3p_netlib_mcstep_
#define newest_ v3p_netlib_newest_
#define nextk_ v3p_netlib_nextk_
#define prn1lb_ v3p_netlib_prn1lb_
#define prn2lb_ v3p_netlib_prn2lb_
#define prn3lb_ v3p_netlib_prn3lb_
#define projgr_ v3p_netlib_projgr_
#define pythag_ v3p_netlib_pythag_
#define qrfac_ v3p_netlib_qrfac_
#define qrsolv_ v3p_netlib_qrsolv_
#define quad_ v3p_netlib_quad_
#define quadit_ v3p_netlib_quadit_
#define quadsd_ v3p_netlib_quadsd_
#define realit_ v3p_netlib_realit_
#define rebak_ v3p_netlib_rebak_
#define reduc_ v3p_netlib_reduc_
#define refine_ v3p_netlib_refine_
#define rg_ v3p_netlib_rg_
#define rpoly_ v3p_netlib_rpoly_
#define rs_ v3p_netlib_rs_
#define rsg_ v3p_netlib_rsg_
#define saxpy_ v3p_netlib_saxpy_
#define sbeg_ v3p_netlib_sbeg_
#define sblas2_ v3p_netlib_sblas2_
#define schck1_ v3p_netlib_schck1_
#define schck2_ v3p_netlib_schck2_
#define schck3_ v3p_netlib_schck3_
#define schck4_ v3p_netlib_schck4_
#define schck5_ v3p_netlib_schck5_
#define scnrm2_ v3p_netlib_scnrm2_
#define scopy_ v3p_netlib_scopy_
#define sdiff_ v3p_netlib_sdiff_
#define sdot_ v3p_netlib_sdot_
#define setdgpfa_ v3p_netlib_setdgpfa_
#define setgpfa_ v3p_netlib_setgpfa_
#define setulb_ v3p_netlib_setulb_
#define sgbmv_ v3p_netlib_sgbmv_
#define sgemv_ v3p_netlib_sgemv_
#define sgeqpf_ v3p_netlib_sgeqpf_
#define sgeqr2_ v3p_netlib_sgeqr2_
#define sger_ v3p_netlib_sger_
#define sgerq2_ v3p_netlib_sgerq2_
#define sggsvd_ v3p_netlib_sggsvd_
#define sggsvp_ v3p_netlib_sggsvp_
#define simpru_ v3p_netlib_simpru_
#define slacpy_ v3p_netlib_slacpy_
#define slags2_ v3p_netlib_slags2_
#define slamc1_ v3p_netlib_slamc1_
#define slamc2_ v3p_netlib_slamc2_
#define slamc3_ v3p_netlib_slamc3_
#define slamc4_ v3p_netlib_slamc4_
#define slamc5_ v3p_netlib_slamc5_
#define slamch_ v3p_netlib_slamch_
#define slange_ v3p_netlib_slange_
#define slapll_ v3p_netlib_slapll_
#define slapmt_ v3p_netlib_slapmt_
#define slapy2_ v3p_netlib_slapy2_
#define slarf_ v3p_netlib_slarf_
#define slarfg_ v3p_netlib_slarfg_
#define slartg_ v3p_netlib_slartg_
#define slas2_ v3p_netlib_slas2_
#define slaset_ v3p_netlib_slaset_
#define slassq_ v3p_netlib_slassq_
#define slasv2_ v3p_netlib_slasv2_
#define smake_ v3p_netlib_smake_
#define smessg_ v3p_netlib_smessg_
#define snrm2_ v3p_netlib_snrm2_
#define sopen_ v3p_netlib_sopen_
#define sorg2r_ v3p_netlib_sorg2r_
#define sorm2r_ v3p_netlib_sorm2r_
#define sormr2_ v3p_netlib_sormr2_
#define sqrdc_ v3p_netlib_sqrdc_
#define sqrsl_ v3p_netlib_sqrsl_
#define srot_ v3p_netlib_srot_
#define srotg_ v3p_netlib_srotg_
#define srule_ v3p_netlib_srule_
#define ssbmv_ v3p_netlib_ssbmv_
#define sscal_ v3p_netlib_sscal_
#define sspmv_ v3p_netlib_sspmv_
#define sspr2_ v3p_netlib_sspr2_
#define sspr_ v3p_netlib_sspr_
#define ssvdc_ v3p_netlib_ssvdc_
#define sswap_ v3p_netlib_sswap_
#define ssymv_ v3p_netlib_ssymv_
#define ssyr2_ v3p_netlib_ssyr2_
#define ssyr_ v3p_netlib_ssyr_
#define stbmv_ v3p_netlib_stbmv_
#define stbsv_ v3p_netlib_stbsv_
#define stgsja_ v3p_netlib_stgsja_
#define stpmv_ v3p_netlib_stpmv_
#define stpsv_ v3p_netlib_stpsv_
#define strmv_ v3p_netlib_strmv_
#define strsv_ v3p_netlib_strsv_
#define subsm_ v3p_netlib_subsm_
#define timer_ v3p_netlib_timer_
#define tql1_ v3p_netlib_tql1_
#define tql2_ v3p_netlib_tql2_
#define tqlrat_ v3p_netlib_tqlrat_
#define trapru_ v3p_netlib_trapru_
#define tred1_ v3p_netlib_tred1_
#define tred2_ v3p_netlib_tred2_
#define urand_ v3p_netlib_urand_
#define xerbla_ v3p_netlib_xerbla_
#define xsimpru_ v3p_netlib_xsimpru_
#define xtrapru_ v3p_netlib_xtrapru_
#define zaxpy_ v3p_netlib_zaxpy_
#define zcopy_ v3p_netlib_zcopy_
#define zdotc_ v3p_netlib_zdotc_
#define zdotu_ v3p_netlib_zdotu_
#define zdrot_ v3p_netlib_zdrot_
#define zdscal_ v3p_netlib_zdscal_
#define zgebak_ v3p_netlib_zgebak_
#define zgebal_ v3p_netlib_zgebal_
#define zgeev_ v3p_netlib_zgeev_
#define zgehd2_ v3p_netlib_zgehd2_
#define zgehrd_ v3p_netlib_zgehrd_
#define zgemm_ v3p_netlib_zgemm_
#define zgemv_ v3p_netlib_zgemv_
#define zgerc_ v3p_netlib_zgerc_
#define zhseqr_ v3p_netlib_zhseqr_
#define zlacgv_ v3p_netlib_zlacgv_
#define zlacpy_ v3p_netlib_zlacpy_
#define zladiv_ v3p_netlib_zladiv_
#define zlahqr_ v3p_netlib_zlahqr_
#define zlahrd_ v3p_netlib_zlahrd_
#define zlange_ v3p_netlib_zlange_
#define zlanhs_ v3p_netlib_zlanhs_
#define zlarf_ v3p_netlib_zlarf_
#define zlarfb_ v3p_netlib_zlarfb_
#define zlarfg_ v3p_netlib_zlarfg_
#define zlarft_ v3p_netlib_zlarft_
#define zlarfx_ v3p_netlib_zlarfx_
#define zlascl_ v3p_netlib_zlascl_
#define zlaset_ v3p_netlib_zlaset_
#define zlassq_ v3p_netlib_zlassq_
#define zlatrs_ v3p_netlib_zlatrs_
#define zqrdc_ v3p_netlib_zqrdc_
#define zqrsl_ v3p_netlib_zqrsl_
#define zscal_ v3p_netlib_zscal_
#define zsvdc_ v3p_netlib_zsvdc_
#define zswap_ v3p_netlib_zswap_
#define ztrevc_ v3p_netlib_ztrevc_
#define ztrmm_ v3p_netlib_ztrmm_
#define ztrmv_ v3p_netlib_ztrmv_
#define ztrsv_ v3p_netlib_ztrsv_
#define zung2r_ v3p_netlib_zung2r_
#define zunghr_ v3p_netlib_zunghr_
#define zungqr_ v3p_netlib_zungqr_
