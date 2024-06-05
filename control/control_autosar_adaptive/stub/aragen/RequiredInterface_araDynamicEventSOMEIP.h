#ifndef RequiredInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
#define RequiredInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
namespace proxy_io {
    class RequiredInterface_Aeb_t final {
        public:
        std::string mEventData;
        RequiredInterface_Aeb_t() = default;
        ~ RequiredInterface_Aeb_t() = default;
        RequiredInterface_Aeb_t(const RequiredInterface_Aeb_t&) = default;
        RequiredInterface_Aeb_t& operator =(const RequiredInterface_Aeb_t&) & = default;
        RequiredInterface_Aeb_t(RequiredInterface_Aeb_t&&) = default;
        RequiredInterface_Aeb_t& operator =(RequiredInterface_Aeb_t&&) & = default;
        void eventData(double implValue) {
             mEventData = ara::com::_RtpsSerialize<double>{}(implValue);
        }
        double eventData() {
            return ara::com::_RtpsDeserialize<double>{}(0, mEventData);
        }
    }; /* class RequiredInterface_Aeb_t */
    class RequiredInterface_Lkas_t final {
        public:
        std::string mEventData;
        RequiredInterface_Lkas_t() = default;
        ~ RequiredInterface_Lkas_t() = default;
        RequiredInterface_Lkas_t(const RequiredInterface_Lkas_t&) = default;
        RequiredInterface_Lkas_t& operator =(const RequiredInterface_Lkas_t&) & = default;
        RequiredInterface_Lkas_t(RequiredInterface_Lkas_t&&) = default;
        RequiredInterface_Lkas_t& operator =(RequiredInterface_Lkas_t&&) & = default;
        void eventData(double implValue) {
             mEventData = ara::com::_RtpsSerialize<double>{}(implValue);
        }
        double eventData() {
            return ara::com::_RtpsDeserialize<double>{}(0, mEventData);
        }
    }; /* class RequiredInterface_Lkas_t */
} /* namespace proxy_io */
namespace proxy_io {
} /* namespace proxy_io */
#endif //RequiredInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
