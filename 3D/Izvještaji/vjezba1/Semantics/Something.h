#pragma once

namespace abc {

	class Something {
		public:
			int* _ptr = nullptr;
			Something(int = -1);
	/*CC*/  Something(const Something&);
	/*MC*/  Something(Something&&) noexcept;
	/*CAO*/ Something& operator = (const Something&);
	/*MAO*/ Something& operator = (Something&&) noexcept;
			virtual ~Something();
	};

}