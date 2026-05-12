#include <vector>
#include <iostream>
#include <vector>
#include <nlopt.hpp>
#include <cmath>
#include <Eigen/Dense>

class MpcHelpers {

private:

  float safe_limit;
  double insertion_step;
  Eigen::MatrixXd tip;
  Eigen::MatrixXd prev_tip;
  Eigen::MatrixXd target;
  Eigen::MatrixXd J;
  std::vector<double> stages;
  std::vector<double> prev_stages;
  std::vector<double> prev_cmd;
  float alpha = 0.65;
  
  void update_jacobian();
  Eigen::MatrixXd process_model(Eigen::MatrixXd y0, std::vector<double> u0, std::vector<double> u, Eigen::MatrixXd Jc);
  
public:

  MpcHelpers(float limit, double ins_step);
  void set_target_pose(std::vector<double> target_vec);
  static double obj_wrapper(const std::vector<double> &x, std::vector<double>& /*grad*/, void* data);
  double objective(const std::vector<double>& uhat, std::vector<double>& /*grad*/, void */*data*/);
  std::vector<double> get_mpc_command(float H, double step_depth, int step, std::vector<double> tip_vec, std::vector<double> stages_vec, int test);

};
