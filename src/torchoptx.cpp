#include <Rcpp.h>
#define TORCHOPTX_HEADERS_ONLY
#include <torchoptx/torchoptx.h>
#define TORCH_IMPL
#define IMPORT_TORCH
#include <torch.h>
#include "exports.h"

void host_exception_handler ()
{
  if (torchoptx_last_error())
  {
    auto msg = Rcpp::as<std::string>(torch::string(torchoptx_last_error()));
    torchoptx_last_error_clear();
    Rcpp::stop(msg);
  }
}

// [[Rcpp::export]]
SEXP optim_sgd_new (torch::TensorList params) {
  return rcpp_torchoptx_sgd(params);
}

// [[Rcpp::export]]
void optim_sgd_step (torchoptx::optim_sgd opt) {
  return rcpp_torchoptx_sgd_step(opt);
}

// [[Rcpp::export]]
void optim_sgd_zero_grad (torchoptx::optim_sgd opt) {
  return rcpp_torchoptx_sgd_zero_grad(opt);
}
