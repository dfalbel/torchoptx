#include <Rcpp.h>
#include "torchoptx_types.h"
#include "exports.h"

namespace torchoptx {

void* optim_sgd::get() {
  return ptr.get();
}

optim_sgd::operator SEXP () const {
  auto xptr = make_xptr<optim_sgd>(*this);
  xptr.attr("class") = Rcpp::CharacterVector::create("torchoptx_optim_sgd");
  return xptr;
}

optim_sgd::optim_sgd (SEXP x) : optim_sgd{Rcpp::as<Rcpp::XPtr<optim_sgd>>(x)->ptr} {}

optim_sgd::optim_sgd (void* x) : ptr(x, rcpp_delete_optim_sgd) {};

/* Adam */

void* optim_adam::get() {
  return ptr.get();
}

optim_adam::operator SEXP () const {
  auto xptr = make_xptr<optim_adam>(*this);
  xptr.attr("class") = Rcpp::CharacterVector::create("torchoptx_optim_adam");
  return xptr;
}

optim_adam::optim_adam (SEXP x) : optim_adam{Rcpp::as<Rcpp::XPtr<optim_adam>>(x)->ptr} {}

optim_adam::optim_adam (void* x) : ptr(x, rcpp_delete_optim_adam) {};

}
