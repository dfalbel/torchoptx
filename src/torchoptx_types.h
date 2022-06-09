#pragma once
#include <torch.h>

namespace torchoptx {

class optim_sgd {
public:
  std::shared_ptr<void> ptr;
  optim_sgd (void* x);
  optim_sgd (std::shared_ptr<void> x) : ptr(x) {}
  optim_sgd (SEXP x);
  operator SEXP () const;
  void* get ();
};

class optim_adam {
public:
  std::shared_ptr<void> ptr;
  optim_adam (void* x);
  optim_adam (std::shared_ptr<void> x) : ptr(x) {}
  optim_adam (SEXP x);
  operator SEXP () const;
  void* get ();
};

}
