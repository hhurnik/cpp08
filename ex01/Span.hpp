#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;

        static unsigned int distanceBetween(int low, int high);

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);

        template <typename InputIterator>
        void addRange(InputIterator first, InputIterator last)
        {
            unsigned int count = 0;

            //counting first keeps the object unchanged when the range is too big
            for (InputIterator it = first; it != last; ++it)
                ++count;
            if (count > _maxSize - static_cast<unsigned int>(_numbers.size()))
                throw SpanFullException();
            _numbers.insert(_numbers.end(), first, last);
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class SpanFullException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };

        class NotEnoughNumbersException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
}

#endif