
#pragma once

#include <map>
#include <climits>

template<typename T,int DEFAULT_VALUE = 0>
class Matrix
{
    using key_type = long long unsigned;
    using value_type = T;
    using data_type = std::map<key_type,value_type>;
    using data_pointer = data_type*;
    using buff_type = struct { key_type key; value_type val;};
    using buff_pointer = buff_type*;

    private:

        buff_type _buff{key_type{},DEFAULT_VALUE};
        data_type _data;

        static void buff_free(data_pointer pdata,buff_pointer pbuff)
        {
            pdata->operator[](pbuff->key) = pbuff->val;
            pbuff->key = key_type{};
            pbuff->val = DEFAULT_VALUE;
        }

    public:

        class MatrixIter
        {
            private:

                key_type _i{};
                buff_pointer _pbuff{nullptr};
                data_pointer _pdata{nullptr};
                decltype(_pdata->begin()) _iter{};

            public:

                MatrixIter(buff_pointer pbuff,data_pointer pdata,int i) 
                    : _i{static_cast<key_type>(i)<<(CHAR_BIT*sizeof(int))}
                    , _pdata{pdata}
                    , _pbuff{pbuff}
                {}

                MatrixIter(buff_pointer pbuff,data_pointer pdata,decltype(_pdata->begin()) iter)
                    : _iter{iter}
                    , _pdata{pdata}
                    , _pbuff{pbuff}
                {}

                ~MatrixIter() = default;

                value_type& operator[](int j)
                {
                    key_type key = _i + static_cast<key_type>(j);

                    if (_pdata->find(key) == _pdata->end())
                    {
                        if (_pbuff->val == DEFAULT_VALUE)
                        {
                            _pbuff->key = key;
                            return _pbuff->val;
                        }

                        Matrix::buff_free(_pdata,_pbuff);
                    } 
                    
                    return _pdata->operator[](key);
                }

                MatrixIter& operator++()
                {
                    if (_iter == _pdata->end())
                        throw std::logic_error("Out of range");

                    ++_iter;

                    return *this; 
                }

                bool operator!=(const MatrixIter& other) const 
                { 
                    return other._iter != _iter; 
                }

                value_type operator*() const { return _iter->second; }
                value_type operator->() const { return _iter->second; }
        };

        MatrixIter operator[] (int i)
        {
            return MatrixIter{&_buff,&_data,i};
        }

        std::size_t size()
        {
            if (_buff.val != DEFAULT_VALUE)
                buff_free(&_data,&_buff);

            return _data.size();
        }

        MatrixIter begin()
        {
            if (_buff.val != DEFAULT_VALUE)
                buff_free(&_data,&_buff);

            return Matrix::MatrixIter{&_buff,&_data,_data.begin()};
        }

        MatrixIter end()
        {
            return Matrix::MatrixIter{&_buff,&_data,_data.end()};
        }
};
