#pragma once

#include <string>
#include <vector>

#include <torch/torch.h>

#include "cpprl/algorithms/algorithm.h"
#include "cpprl/model/policy.h"
#include "cpprl/storage.h"

namespace cpprl
{
class A2C : public Algorithm
{
  private:
    Policy *policy;
    float value_loss_coef, entropy_coef, max_grad_norm;
    std::unique_ptr<torch::optim::Optimizer> optimizer;

  public:
    A2C(Policy &policy,
        float value_loss_coef,
        float entropy_coef,
        float learning_rate,
        float epsilon,
        float alpha,
        float max_grad_norm);

    std::vector<UpdateDatum> update(RolloutStorage &rollouts);
};
}