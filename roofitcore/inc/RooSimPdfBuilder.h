/*****************************************************************************
 * Project: BaBar detector at the SLAC PEP-II B-factory
 * Package: RooFitTools
 *    File: $Id: RooSimPdfBuilder.rdl,v 1.3 2001/11/21 21:35:05 verkerke Exp $
 * Authors:
 *   WV, Wouter Verkerke, UC Santa Barbara, verkerke@slac.stanford.edu
 * History:
 *   17-Oct-2001 WV Created initial version
 *
 * Copyright (C) 2000 University of California
 *****************************************************************************/
#ifndef ROO_SIM_PDF_BUILDER
#define ROO_SIM_PDF_BUILDER

#include "Rtypes.h"
#include "RooFitCore/RooArgSet.hh"
#include "RooFitCore/RooArgList.hh"
class RooAbsPdf ;
class RooCategory ;

class RooSimPdfBuilder {
public:

  RooSimPdfBuilder(const RooArgSet& pdfProtoList) ;
  ~RooSimPdfBuilder() ;

  RooArgSet* createProtoBuildConfig() ;
  const RooAbsPdf* buildPdf(const RooArgSet& buildConfig, const RooAbsData* dataSet, 
			    const RooArgSet& auxSplitCats, Bool_t verbose=kFALSE) {
    return buildPdf(buildConfig,dataSet,&auxSplitCats,verbose) ;
  }
  const RooAbsPdf* buildPdf(const RooArgSet& buildConfig, const RooAbsData* dataSet, 
			    const RooArgSet* auxSplitCats=0, Bool_t verbose=kFALSE) ;
  
  const RooArgSet& splitLeafList() { return _splitLeafList; }
 
protected:

  RooArgSet _protoPdfSet ;       // Set of prototype PDFS

  RooArgSet _compSplitCatSet ;   // List of owned composite splitting categories
  RooArgSet _splitLeafList ;     // List of owned split leafs
  TList     _retiredCustomizerList ; // Retired customizer from previous builds (own their PDF branch nodes)

private:
  RooSimPdfBuilder(const RooSimPdfBuilder&) ; // No copying allowed

protected:
  ClassDef(RooSimPdfBuilder,0) // RooSimultaneous PDF Builder 
};

#endif
