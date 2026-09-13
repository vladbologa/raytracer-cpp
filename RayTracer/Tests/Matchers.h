#pragma once

#include "pch.h"

#include <cmath>

// Matcher for two Eigen vectors (i.e. 1D matrices)
MATCHER_P2(IsSimilarToVector, expected, epsilon, "") {
    if (arg.size() != expected.size()) {
        *result_listener << "vector sizes do not match";
        return false;
    }

    for (Eigen::Index i = 0; i < arg.size(); ++i) {
        if (std::abs(arg[i] - expected[i]) > epsilon) {
            *result_listener << "elements at index " << i << " are not similar: " << arg[i] << " "
                             << expected[i];
            return false;
        }
    }

    return true;
}

// Matcher for two Eigen matrices
MATCHER_P2(IsSimilarToMatrix, expected, epsilon, "") {
    if (arg.rows() != expected.rows() || arg.cols() != expected.cols()) {
        *result_listener << "matrix sizes do not match";
        return false;
    }

    for (Eigen::Index i = 0; i < arg.rows(); ++i) {
        const auto rowArg = arg.row(i);
        const auto rowExpected = expected.row(i);
        for (Eigen::Index j = 0; j < rowArg.size(); ++j) {
            if (std::abs(rowArg[j] - rowExpected[j]) > epsilon) {
                *result_listener << "elements at (row " << i << ", column " << j
                                 << ") are not similar: " << rowArg[j] << " " << rowExpected[j];
                return false;
            }
        }
    }

    return true;
}