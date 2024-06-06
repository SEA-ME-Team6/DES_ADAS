#ifndef ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
namespace skeleton_io {
    class ProvidedInterface_Distance_error_t final {
        public:
        std::string mEventData;
        ProvidedInterface_Distance_error_t() = default;
        ~ ProvidedInterface_Distance_error_t() = default;
        ProvidedInterface_Distance_error_t(const ProvidedInterface_Distance_error_t&) = default;
        ProvidedInterface_Distance_error_t& operator =(const ProvidedInterface_Distance_error_t&) & = default;
        ProvidedInterface_Distance_error_t(ProvidedInterface_Distance_error_t&&) = default;
        ProvidedInterface_Distance_error_t& operator =(ProvidedInterface_Distance_error_t&&) & = default;
        void eventData(double implValue) {
             mEventData = ara::com::_RtpsSerialize<double>{}(implValue);
        }
        double eventData() {
            return ara::com::_RtpsDeserialize<double>{}(0, mEventData);
        }
    }; /* class ProvidedInterface_Distance_error_t */
    class ProvidedInterface_Throttle_t final {
        public:
        std::string mEventData;
        ProvidedInterface_Throttle_t() = default;
        ~ ProvidedInterface_Throttle_t() = default;
        ProvidedInterface_Throttle_t(const ProvidedInterface_Throttle_t&) = default;
        ProvidedInterface_Throttle_t& operator =(const ProvidedInterface_Throttle_t&) & = default;
        ProvidedInterface_Throttle_t(ProvidedInterface_Throttle_t&&) = default;
        ProvidedInterface_Throttle_t& operator =(ProvidedInterface_Throttle_t&&) & = default;
        void eventData(double implValue) {
             mEventData = ara::com::_RtpsSerialize<double>{}(implValue);
        }
        double eventData() {
            return ara::com::_RtpsDeserialize<double>{}(0, mEventData);
        }
    }; /* class ProvidedInterface_Throttle_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
