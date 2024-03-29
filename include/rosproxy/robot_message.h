// Generated by gencpp from file rosproxy/robot_message.msg
// DO NOT EDIT!


#ifndef ROSPROXY_MESSAGE_ROBOT_MESSAGE_H
#define ROSPROXY_MESSAGE_ROBOT_MESSAGE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosproxy
{
template <class ContainerAllocator>
struct robot_message_
{
  typedef robot_message_<ContainerAllocator> Type;

  robot_message_()
    : message_code(0)
    , message_body()  {
      message_body.assign(0);
  }
  robot_message_(const ContainerAllocator& _alloc)
    : message_code(0)
    , message_body()  {
  (void)_alloc;
      message_body.assign(0);
  }



   typedef uint32_t _message_code_type;
  _message_code_type message_code;

   typedef boost::array<uint8_t, 124>  _message_body_type;
  _message_body_type message_body;





  typedef boost::shared_ptr< ::rosproxy::robot_message_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosproxy::robot_message_<ContainerAllocator> const> ConstPtr;

}; // struct robot_message_

typedef ::rosproxy::robot_message_<std::allocator<void> > robot_message;

typedef boost::shared_ptr< ::rosproxy::robot_message > robot_messagePtr;
typedef boost::shared_ptr< ::rosproxy::robot_message const> robot_messageConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosproxy::robot_message_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosproxy::robot_message_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rosproxy::robot_message_<ContainerAllocator1> & lhs, const ::rosproxy::robot_message_<ContainerAllocator2> & rhs)
{
  return lhs.message_code == rhs.message_code &&
    lhs.message_body == rhs.message_body;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rosproxy::robot_message_<ContainerAllocator1> & lhs, const ::rosproxy::robot_message_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rosproxy

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::rosproxy::robot_message_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosproxy::robot_message_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosproxy::robot_message_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosproxy::robot_message_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosproxy::robot_message_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosproxy::robot_message_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosproxy::robot_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8272c5d690c09f77921ae0291567e2ab";
  }

  static const char* value(const ::rosproxy::robot_message_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8272c5d690c09f77ULL;
  static const uint64_t static_value2 = 0x921ae0291567e2abULL;
};

template<class ContainerAllocator>
struct DataType< ::rosproxy::robot_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosproxy/robot_message";
  }

  static const char* value(const ::rosproxy::robot_message_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosproxy::robot_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 message_code\n"
"uint8[124] message_body\n"
;
  }

  static const char* value(const ::rosproxy::robot_message_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosproxy::robot_message_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.message_code);
      stream.next(m.message_body);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct robot_message_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosproxy::robot_message_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosproxy::robot_message_<ContainerAllocator>& v)
  {
    s << indent << "message_code: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.message_code);
    s << indent << "message_body[]" << std::endl;
    for (size_t i = 0; i < v.message_body.size(); ++i)
    {
      s << indent << "  message_body[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.message_body[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSPROXY_MESSAGE_ROBOT_MESSAGE_H
