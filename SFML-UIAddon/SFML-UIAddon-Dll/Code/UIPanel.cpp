#include "Headers/SFMLUIAddon/UIPanel.hpp"

namespace sfui
{
	UIPanel::UIPanel()
	{
	}

	UIPanel::~UIPanel()
	{
	}

	void UIPanel::setActive(bool _active)
	{
		m_active = _active;
	}

	bool UIPanel::isActive() const noexcept
	{
		return m_active;
	}
}
