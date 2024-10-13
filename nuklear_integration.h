#pragma once

#include <MultiEngine/math/Math.h>

#include <limits>
#include <string>
#include <charconv>

#include <stb_sprintf.h>

namespace nuklear_integration {
	inline float64 strtod_wrapper(const char* str, char** str_end) noexcept {
		float64 value = 0.0;
		const auto result = std::from_chars(str, str + std::strlen(str), value);
		if (result.ec != std::errc{}) {
			return std::numeric_limits<float64>::max();
		}

        MLE_CORE_ASSERT(str_end == nullptr,
                        "Nuklear made it non-const, but that is wrong, so it should never expect a result.");

		/*if (str_end != nullptr) {
			(*str_end) = result.ptr;
		}*/

		return value;
	}

	inline char* dtoa_wrapper(char* str, const float64 value) noexcept {
		const auto result = std::to_chars(str, str + std::strlen(str), value);
		return str;
	}
}

#define NK_ASSERT(expr)		MLE_CORE_ASSERT(expr)

#define NK_MEMSET			::std::memset
#define NK_MEMCPY			::std::memcpy
#define NK_VSNPRINTF		::stbsp_snprintf
#define NK_SIN				::MultiEngine::sin
#define NK_COS				::MultiEngine::cos
#define NK_INV_SQRT			::MultiEngine::rcp_sqrt
#define NK_DTOA				::nuklear_integration::dtoa_wrapper
#define NK_STRTOD			::nuklear_integration::strtod_wrapper

#define NK_UINT_DRAW_INDEX
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_COMMAND_USERDATA
#define NK_INCLUDE_STANDARD_VARARGS
// #define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_NO_STB_TRUETYPE_IMPLEMENTATION
#define NK_NO_STB_RECT_PACK_IMPLEMENTATION
#include "nuklear.h"
