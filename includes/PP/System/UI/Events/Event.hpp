/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Events/Event.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_EVENTS_EVENT_HPP
#define PP_SYSTEM_UI_EVENTS_EVENT_HPP

#include <algorithm>
#include <deque>

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /*** base class for handler wrapper instances ***/
            class BaseDelegate
            {    
            public:
                BaseDelegate(void* pobject, void* pfn) { m_pObject = pobject; m_pFn = pfn; }
                BaseDelegate(const BaseDelegate& rhs) { m_pObject = rhs.m_pObject; m_pFn = rhs.m_pFn; }
                bool Equals(const BaseDelegate& rhs) const { return m_pObject == rhs.m_pObject && m_pFn == rhs.m_pFn; }

            protected:
                void* GetFn() { return m_pFn; }
                void* GetObject() { return m_pObject; }

            private:
                void* m_pObject;
                void* m_pFn;
            };


            template <class A>
            class BaseDelegate1 : public BaseDelegate     
            {    
            public:
                BaseDelegate1(void* pobject, void* pfn) : BaseDelegate(pobject, pfn){;}
                BaseDelegate1(const BaseDelegate1& rhs) : BaseDelegate(rhs){;}
                void operator() (A arg) { Execute(arg); }     
                virtual BaseDelegate1* Copy() = 0;

            protected:
                virtual void Execute(A arg) = 0;
            };

            template <class A1, class A2>
            class BaseDelegate2 : public BaseDelegate          
            {    
            public:
                BaseDelegate2(void* pobject, void* pfn) : BaseDelegate(pobject, pfn){;}
                BaseDelegate2(const BaseDelegate2& rhs) : BaseDelegate(rhs){;}
                void operator() (A1 arg1, A2 arg2) { Execute(arg1, arg2); }     
                virtual BaseDelegate2* Copy() = 0;

            protected:
                virtual void Execute(A1 arg1, A2 arg2) = 0;
            };

            /*** handler wrapper for global and static functions  ***/
            template <class A>
            class StaticDelegate1: public BaseDelegate1<A>
            {
                typedef void (*FnPtr)(A);
            public:
                StaticDelegate1(FnPtr pFn) : BaseDelegate1(NULL, pFn) {;} 
                StaticDelegate1(const StaticDelegate1& rhs) : BaseDelegate1(rhs) {;} 
                virtual BaseDelegate1<A>* Copy() { return new StaticDelegate1(*this); }

            protected:
                virtual void Execute(A arg)
                {
                    FnPtr pfn = (FnPtr)GetFn();
                    (*pfn)(arg); 
                }
            };

            template <class A1, class A2>
            class StaticDelegate2: public BaseDelegate2<A1, A2>
            {
                typedef void (*FnPtr)(A1, A2);
            public:
                StaticDelegate2(FnPtr pFn) : BaseDelegate2(NULL, pFn) {;} 
                StaticDelegate2(const StaticDelegate2& rhs) : BaseDelegate2(rhs) {;} 
                virtual BaseDelegate2<A1, A2>* Copy() { return new StaticDelegate2(*this); }

            protected:
                virtual void Execute(A1 arg1, A2 arg2)
                {
                    FnPtr pfn = (FnPtr)GetFn();
                    (*pfn)(arg1, arg2); 
                }
            };

            /*** handler wrapper for non-static member functions  ***/
            // type of the object (O) differs from type to which member function belongd (T)
            // because that makes it possible to use member methods from base classes
            template <class O, class T, class A>
            class Delegate1    : public BaseDelegate1<A>
            {
                typedef void (T::* FnPtr)(A);
            public:
                Delegate1(O* pObj, FnPtr pFn) : BaseDelegate1(pObj, &pFn), m_pFn(pFn) {;}
                Delegate1(const Delegate1& rhs) : BaseDelegate1(rhs) { m_pFn = rhs.m_pFn; } 
                virtual BaseDelegate1* Copy() { return new Delegate1(*this); }

            protected:
                virtual void Execute(A arg)
                {
                    O* pobj = (O*) GetObject();
                    (pobj->*m_pFn)(arg); 
                }  

            private:
                FnPtr m_pFn;
            };

            template <class O, class T, class A1, class A2>
            class Delegate2    : public BaseDelegate2<A1, A2>
            {
                typedef void (T::* FnPtr)(A1, A2);
            public:
                Delegate2(O* pObj, FnPtr pFn) : BaseDelegate2(pObj, &pFn), m_pFn(pFn) {;}
                Delegate2(const Delegate2& rhs) : BaseDelegate2(rhs) { m_pFn = rhs.m_pFn; } 
                virtual BaseDelegate2<A1, A2>* Copy() { return new Delegate2(*this); }

            protected:
                virtual void Execute(A1 arg1, A2 arg2)
                {
                    O* pobj = (O*) GetObject();
                    (pobj->*m_pFn)(arg1, arg2); 
                }  

            private:
                FnPtr m_pFn;
            };

            /*** helper functions to instantiate handler ***/
            template <class O, class T, class A>
            Delegate1<O, T, A> EventHandler(O* pObj, void (T::* pFn)(A))
            {
                return Delegate1<O, T, A>(pObj, pFn);
            }

            template <class A>
            StaticDelegate1<A> EventHandler(void (*pFn)(A))
            {
                return StaticDelegate1<A>(pFn); 
            }

            template <class O, class T, class A1, class A2>
            Delegate2<O, T, A1, A2> EventHandler(O* pObj, void (T::* pFn)(A1, A2))
            {
                return Delegate2<O, T, A1, A2>(pObj, pFn);
            }

            template <class A1, class A2>
            StaticDelegate2<A1, A2> EventHandler(void (*pFn)(A1, A2))
            {
                return StaticDelegate2<A1, A2>(pFn); 
            }

            /*** helper class for searching through handler list ***/
            template <class T>
            class finder
            {      
                const T* m_obj;
            public:
                finder(T* obj) : m_obj(obj){;}
                bool operator()(const T* obj){ return obj->Equals(*m_obj); }        
            };

            /*** event base implementation ***/
            template <class ARG>
            class EventBase1
            {
            protected:
                typedef BaseDelegate1<ARG> Delegate;
                typedef Delegate* DelegatePtr; 
                typedef std::deque<DelegatePtr> DelegateList;
                typedef typename DelegateList::iterator DelegateIterator;
                typedef void (*FnPtrType)(ARG);

                DelegateList m_delegates;

            public:
                ~EventBase1()
                {
                    for(DelegateIterator it = m_delegates.begin(); it != m_delegates.end(); ++it)
                        delete *it;
                }

                void operator+= (Delegate& del)
                { 
                    finder<Delegate> f(&del);
                    if(std::find_if(m_delegates.begin(), m_delegates.end(), f) != m_delegates.end())
                    {
                        return;
                    }

                    m_delegates.push_back(del.Copy()); 
                }

                void operator+= (FnPtrType pfn)
                { 
                    (*this) += EventHandler(pfn);
                }

                void operator-= (Delegate& del) 
                { 
                    finder<Delegate> f(&del);
                    DelegateIterator it = std::find_if(m_delegates.begin(), m_delegates.end(), f);
                    if(it != m_delegates.end())
                    {           
                        delete *it;
                        m_delegates.erase(it); 
                    }
                }

                void operator-= (FnPtrType pfn)
                { 
                    (*this) -= EventHandler(pfn);
                }

                void Invoke(ARG a)
                {
                    for(DelegateIterator it = m_delegates.begin(); it != m_delegates.end(); ++it)
                    {
                        (*(*it))(a);
                    }
                }

                void operator() (ARG a) 
                { 
                    for(DelegateIterator it = m_delegates.begin(); it != m_delegates.end(); ++it)
                    {
                        (*(*it))(a);
                    }
                }

                size_t getSubscriberCount() const { return m_delegates.size(); }
            };


            template <class ARG1, class ARG2>
            class EventBase2
            {
            protected:
                typedef BaseDelegate2<ARG1, ARG2> Delegate;
                typedef Delegate* DelegatePtr; 
                typedef std::deque<DelegatePtr> DelegateList;
                typedef typename DelegateList::iterator DelegateIterator;
                typedef void (*FnPtrType)(ARG1, ARG2);

                DelegateList m_delegates;

            public:
                ~EventBase2()
                {
                    for (DelegateIterator it = m_delegates.begin(); it != m_delegates.end(); ++it)
                    {
                        delete *it;
                    }
                }

                void operator+= (Delegate& del)
                { 
                    finder<Delegate> f(&del);
                    if (std::find_if(m_delegates.begin(), m_delegates.end(), f) != m_delegates.end())
                    {
                        return;
                    }

                    m_delegates.push_back(del.Copy()); 
                }

                void operator+= (FnPtrType pfn)
                { 
                    (*this) += EventHandler(pfn);
                }

                void operator-= (Delegate& del) 
                { 
                    finder<Delegate> f(&del);
                    DelegateIterator it = std::find_if(m_delegates.begin(), m_delegates.end(), f);
                    if(it != m_delegates.end())
                    {           
                        delete *it;
                        m_delegates.erase(it); 
                    }
                }

                void operator-= (FnPtrType pfn)
                { 
                    (*this) -= EventHandler(pfn);
                }

                void operator() (ARG1 a1, ARG2 a2) 
                { 
                    for(DelegateIterator it = m_delegates.begin(); it != m_delegates.end(); ++it)
                    {
                        (*(*it))(a1, a2);
                    }
                }

                size_t getSubscriberCount() const { return m_delegates.size(); }
            };

            /** Typelist helpers **/
            template <class H, class T>
            struct Typelist
            {
                typedef H head;
                typedef T tail;
            };

            class NullTypelist {};

            /** event template **/
            template <class ARG1, class ARG2 = NullTypelist>
            class Event : public EventBase2<ARG1, ARG2>
            {
            };

            template <class ARG>
            class Event<ARG, NullTypelist> : public EventBase1<ARG> // partially specialized
            {
            };
        }
    }
}

#endif
