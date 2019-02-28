
#ifndef __ncdfFlowAPI_h__
#define __ncdfFlowAPI_h__


#ifdef __cplusplus
extern "C" {
#endif


SEXP ncdfFlow_readFrame(SEXP xSEXP, SEXP i_objSEXP, SEXP j_objSEXP, SEXP useExprSEXP);

SEXP ncdfFlow_open_hdf(SEXP filenameSEXP, SEXP flagsSEXP, SEXP fileidSEXP, SEXP datasetSEXP, SEXP dataspaceSEXP, SEXP is3dSEXP);

SEXP ncdfFlow_get_event_number(SEXP fileidSEXP, SEXP datasetSEXP, SEXP dataspaceSEXP, SEXP sampleIndxSEXP, SEXP is3dSEXP);

SEXP ncdfFlow_readSlice(SEXP fileidSEXP, SEXP datasetSEXP, SEXP dataspaceSEXP, SEXP chIndxSEXP, SEXP sampleIndxSEXP, SEXP nEventsSEXP, SEXP data_outSEXP, SEXP is3dSEXP);

SEXP ncdfFlow_close_hdf(SEXP fileidSEXP);

#ifdef __cplusplus
}
#endif


#endif
