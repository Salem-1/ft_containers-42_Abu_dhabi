
#ifndef STACK_HPP
# define STACK_HPP
# include <iostream>
# include "../vector/vector.hpp"

namespace ft{
    template <class T, class Container = ft::vector<T> > 
    class stack
    {
        protected:
            Container   encapsule;
    	public:
            typedef T                                 value_type;
            typedef Container                         container_type;
            typedef typename Container::size_type     size_type;
            Container get_container() const
            {
                return (encapsule);
            }
            stack (const container_type& ctnr = container_type()): encapsule(ctnr)
            {};
            bool empty() const
            {
                return (encapsule.empty());
            };
            size_type size() const
            {
                return (encapsule.size());
            };
             value_type& top()
             {
                return(encapsule.back());
             }
             const value_type& top() const
             {
                return(encapsule.back());
             }
            void push (const value_type& val)
            {
                encapsule.push_back(val);
            }
            void pop()
            {
                encapsule.pop_back();
            }
            void swap (stack& x)
            {
                encapsule.swap(x.encapsule);
            } 
        
    };
    template <class T, class Container>
     bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
     {
        return (lhs.get_container() == rhs.get_container());
     }
    template <class T, class Container>
     bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
     {
        return (lhs.get_container() != rhs.get_container());
     }	
    template <class T, class Container>
     bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
     {
        return (lhs.get_container() < rhs.get_container());
     }	
    template <class T, class Container>
     bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
     {
        return (lhs.get_container() <= rhs.get_container());
     }
    template <class T, class Container>
     bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
     {
        return (lhs.get_container() > rhs.get_container());
     }
    template <class T, class Container>
     bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
     {
        return (lhs.get_container() >= rhs.get_container());
     }
     template <class T, class Container> 
     void swap (stack<T,Container>& x, stack<T,Container>& y)
     {
        x.swap(y);
     };
}  
#endif
