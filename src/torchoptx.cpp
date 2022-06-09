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
SEXP optim_sgd_new (torch::TensorList params, double lr, double momentum, double dampening,
                    double weight_decay, bool nesterov) {
  return rcpp_torchoptx_sgd(params, lr, momentum, dampening, weight_decay, nesterov);
}

// [[Rcpp::export]]
void optim_sgd_step (torchoptx::optim_sgd opt) {
  return rcpp_torchoptx_sgd_step(opt);
}

// [[Rcpp::export]]
void optim_sgd_zero_grad (torchoptx::optim_sgd opt) {
  return rcpp_torchoptx_sgd_zero_grad(opt);
}

// [[Rcpp::export]]
SEXP optim_adam_new (torch::TensorList params, double lr, double betas0, double betas1,
                     double eps, double weight_decay, bool amsgrad) {
  return rcpp_torchoptx_adam(params, lr, betas0, betas1, eps, weight_decay, amsgrad);
}

// [[Rcpp::export]]
void optim_adam_step (torchoptx::optim_adam opt) {
  return rcpp_torchoptx_adam_step(opt);
}

// [[Rcpp::export]]
void optim_adam_zero_grad (torchoptx::optim_adam opt) {
  return rcpp_torchoptx_adam_zero_grad(opt);
}
