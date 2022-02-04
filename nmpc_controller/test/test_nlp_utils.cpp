#include <ros/ros.h>
#include <gtest/gtest.h>

#include <nmpc_controller/quad_nlp.h>
#include <chrono>

TEST(NMPCTest, testGetNumVariables)
{
	int type = NONE;
    int N = 10;
    int n = 2;
    int n_null = 1;
	int n_complex = n + n_null;
    int m = 1;
    double dt = 1;
    double mu = 1;
    double panic_weights = 1;
    Eigen::MatrixXd Q(n,1);
    Eigen::MatrixXd R(m,1);
    Eigen::MatrixXd Q_factor(n,1);
    Eigen::MatrixXd R_factor(m,1);
    Eigen::MatrixXd x_min(n,1);
    Eigen::MatrixXd x_max(n,1);
    Eigen::MatrixXd x_min_complex(n_complex,1);
    Eigen::MatrixXd x_max_complex(n_complex,1);
    Eigen::MatrixXd u_min(m,1);
    Eigen::MatrixXd u_max(m,1);

	double state_weight = 1;
	double input_weight = 0;

	Q.fill(state_weight);
	R.fill(input_weight);
	Q_factor.fill(1);
	R_factor.fill(1);
	x_min.fill(-1);
	x_max.fill(1);
	x_min_complex.fill(-1);
	x_max_complex.fill(1);
	u_min.fill(-10);
	u_max.fill(10);

	std::cout << "Q\n" << Q << std::endl;
	std::cout << "R\n" << R << std::endl;
	std::cout << "Q_factor\n" << Q_factor << std::endl;
	std::cout << "R_factor\n" << R_factor << std::endl;
	std::cout << "x_min\n" << x_min << std::endl;
	std::cout << "x_max\n" << x_max << std::endl;
	std::cout << "x_min_complex\n" << x_min_complex << std::endl;
	std::cout << "x_max_complex\n" << x_max_complex << std::endl;
	std::cout << "u_min\n" << u_min << std::endl;
	std::cout << "u_max\n" << u_max << std::endl;

	// quadNLP nlp(type, N, n, n_null, m, dt, mu, panic_weights, Q, R, Q_factor, R_factor,
	// 	x_min, x_max, x_min_complex, x_max_complex, u_min, u_max);

	// Eigen::VectorXi complexity_schedule(N);
	
	// complexity_schedule.setZero();
	// nlp.update_complexity_schedule(complexity_schedule);

	// int n_vars = nlp.getNumVariables();
	// int n_constraints = nlp.getNumConstraints();

	// std::cout << "n_vars = " << n_vars << std::endl;
	// std::cout << "n_constraints = " << n_constraints << std::endl;

	// EXPECT_EQ(n_vars, (n*3+m)*N);

	// complexity_schedule.fill(1);
	// nlp.update_complexity_schedule(complexity_schedule);

	// n_vars = nlp.getNumVariables();
	// n_constraints = nlp.getNumConstraints();

	// std::cout << "n_vars = " << n_vars << std::endl;
	// std::cout << "n_constraints = " << n_constraints << std::endl;

	// EXPECT_EQ(n_vars, (n_complex*3+m)*N);

}