#ifndef PARAMETER_LIST_H
#define PARAMETER_LIST_H

#include <vector>
#include <utility>
#include <string>

/// A list of parameters to be passed to a Smartt Function
/// Created to be used as a Builder class.
/// Example: ParameterList()("investment_code", "auto")("order_type", 0);
class ParameterList {
    public:
        ParameterList();

        /// A list with no parameters set
        static const ParameterList EMPTY_LIST;

        /// Add a parameter's value to the list
        /// \return the same @ParameterList, for subsequent additions
        ParameterList &operator()(const std::string &parameterName, const char *parameterValue);

        /// Add a parameter's value to the list
        /// \return the same @ParameterList, for subsequent additions
        ParameterList &operator()(const std::string &parameterName, std::string parameterValue);

        /// Add a parameter's value to the list
        /// \return the same @ParameterList, for subsequent additions
        ParameterList &operator()(const std::string &parameterName, double parameterValue);

        /// Add a parameter's value to the list
        /// \return the same @ParameterList, for subsequent additions
        ParameterList &operator()(const std::string &parameterName, bool parameterValue);

        /// Add a parameter's value to the list
        /// \return the same @ParameterList, for subsequent additions
        ParameterList &operator()(const std::string &parameterName, int parameterValue);

        /// \return the number of set parameters
        size_t size() const;

        /// \return the name of the @i -th set parameter
        std::string parameterName(unsigned i) const;

        /// \return the value of the @i -th set parameter
        std::string parameterValue(unsigned i) const;

    private:
        std::vector <std::pair <std::string, std::string> > values_;
};

#endif
