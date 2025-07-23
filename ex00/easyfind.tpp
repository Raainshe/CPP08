/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:59:46 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 13:21:43 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return std::distance(container.begin(), it);
};

class runtime_error: public std::exception
{
    private:
        std::string _message;

    public:
        runtime_error(const std::string& message)
        : std::exception(), _message(message)
        {
            std::cout << "runtime_error: " << message << std::endl;
        }

        virtual ~runtime_error() throw()
        {
        }

        virtual const char* what() const throw()
        {
            return _message.c_str();
        }
};