// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_import_lite.proto

#include "google/protobuf/unittest_import_lite.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace protobuf_unittest_import {
class ImportMessageLiteDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ImportMessageLite> _instance;
} _ImportMessageLite_default_instance_;
}  // namespace protobuf_unittest_import
static void InitDefaultsscc_info_ImportMessageLite_google_2fprotobuf_2funittest_5fimport_5flite_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protobuf_unittest_import::_ImportMessageLite_default_instance_;
    new (ptr) ::protobuf_unittest_import::ImportMessageLite();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protobuf_unittest_import::ImportMessageLite::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ImportMessageLite_google_2fprotobuf_2funittest_5fimport_5flite_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ImportMessageLite_google_2fprotobuf_2funittest_5fimport_5flite_2eproto}, {}};

namespace protobuf_unittest_import {
bool ImportEnumLite_IsValid(int value) {
  switch (value) {
    case 7:
    case 8:
    case 9:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> ImportEnumLite_strings[3] = {};

static const char ImportEnumLite_names[] =
  "IMPORT_LITE_BAR"
  "IMPORT_LITE_BAZ"
  "IMPORT_LITE_FOO";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry ImportEnumLite_entries[] = {
  { {ImportEnumLite_names + 0, 15}, 8 },
  { {ImportEnumLite_names + 15, 15}, 9 },
  { {ImportEnumLite_names + 30, 15}, 7 },
};

static const int ImportEnumLite_entries_by_number[] = {
  2, // 7 -> IMPORT_LITE_FOO
  0, // 8 -> IMPORT_LITE_BAR
  1, // 9 -> IMPORT_LITE_BAZ
};

const std::string& ImportEnumLite_Name(
    ImportEnumLite value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          ImportEnumLite_entries,
          ImportEnumLite_entries_by_number,
          3, ImportEnumLite_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      ImportEnumLite_entries,
      ImportEnumLite_entries_by_number,
      3, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     ImportEnumLite_strings[idx].get();
}
bool ImportEnumLite_Parse(
    const std::string& name, ImportEnumLite* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      ImportEnumLite_entries, 3, name, &int_value);
  if (success) {
    *value = static_cast<ImportEnumLite>(int_value);
  }
  return success;
}

// ===================================================================

void ImportMessageLite::InitAsDefaultInstance() {
}
class ImportMessageLite::_Internal {
 public:
  using HasBits = decltype(std::declval<ImportMessageLite>()._has_bits_);
  static void set_has_d(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

ImportMessageLite::ImportMessageLite()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protobuf_unittest_import.ImportMessageLite)
}
ImportMessageLite::ImportMessageLite(const ImportMessageLite& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  d_ = from.d_;
  // @@protoc_insertion_point(copy_constructor:protobuf_unittest_import.ImportMessageLite)
}

void ImportMessageLite::SharedCtor() {
  d_ = 0;
}

ImportMessageLite::~ImportMessageLite() {
  // @@protoc_insertion_point(destructor:protobuf_unittest_import.ImportMessageLite)
  SharedDtor();
}

void ImportMessageLite::SharedDtor() {
}

void ImportMessageLite::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ImportMessageLite& ImportMessageLite::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ImportMessageLite_google_2fprotobuf_2funittest_5fimport_5flite_2eproto.base);
  return *internal_default_instance();
}


void ImportMessageLite::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf_unittest_import.ImportMessageLite)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  d_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ImportMessageLite::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 d = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_d(&has_bits);
          d_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ImportMessageLite::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protobuf_unittest_import.ImportMessageLite)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 d = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_d(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields().data(),
        static_cast<int>(_internal_metadata_.unknown_fields().size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf_unittest_import.ImportMessageLite)
  return target;
}

size_t ImportMessageLite::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf_unittest_import.ImportMessageLite)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional int32 d = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_d());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields().size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ImportMessageLite::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ImportMessageLite*>(
      &from));
}

void ImportMessageLite::MergeFrom(const ImportMessageLite& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf_unittest_import.ImportMessageLite)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_d()) {
    _internal_set_d(from._internal_d());
  }
}

void ImportMessageLite::CopyFrom(const ImportMessageLite& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf_unittest_import.ImportMessageLite)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ImportMessageLite::IsInitialized() const {
  return true;
}

void ImportMessageLite::InternalSwap(ImportMessageLite* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(d_, other->d_);
}

std::string ImportMessageLite::GetTypeName() const {
  return "protobuf_unittest_import.ImportMessageLite";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf_unittest_import
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protobuf_unittest_import::ImportMessageLite* Arena::CreateMaybeMessage< ::protobuf_unittest_import::ImportMessageLite >(Arena* arena) {
  return Arena::CreateInternal< ::protobuf_unittest_import::ImportMessageLite >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
