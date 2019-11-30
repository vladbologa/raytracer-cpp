#pragma once

#include "pch.h"

// Matcher for two Eigen vectors (i.e. 1D matrices)
MATCHER_P2(IsSimilarToVector, expected, epsilon, "") {
    if (arg.size() != expected.size()) {
        *result_listener << "vector sizes do not match";
        return false;
    }

    //TODO: Eigen 3.4 will support STL iterators
    for (Eigen::Index i = 0; i < arg.size(); i++) {
        if (fabs(arg[i] - expected[i]) > epsilon) {
            *result_listener << "elements at index " << i << " are not similar: "
                << arg[i] << " " << expected[i];
            return false;
        }
    }

    return true;
}