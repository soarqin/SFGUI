#pragma once
#include <SFGUI/Bin.hpp>
#include <SFGUI/Label.hpp>
#include <SFML/System/String.hpp>

namespace sfg {

/** Pushbutton.
 */
class SFGUI_API Button : public Bin {
	public:
		typedef boost::shared_ptr<Button>  Ptr; //!< Shared pointer.
		typedef boost::shared_ptr<const Button>  PtrConst; //!< Shared pointer.

		/** Create button.
		 * @param label Label.
		 * @return Button.
		 */
		static Ptr Create( const sf::String& label = L"" );

		virtual const std::string& GetName() const;

		/** Set label.
		 * @param label Label.
		 */
		void SetLabel( const sf::String& label );

		/* Get label.
		 * @return Label.
		 */
		const sf::String& GetLabel() const;

		/** Set padding.
		 * @param padding Padding.
		 */
		void SetPadding( float padding );

		/** Get padding.
		 * @return Padding.
		 */
		float GetPadding() const;

		Signal OnClick; //!< Fired when button clicked.

	protected:
		sf::Drawable* InvalidateImpl();
		sf::Vector2f GetRequisitionImpl() const;

	private:
		Button();

		void HandleStateChange();
		void HandleMouseEnter();
		void HandleMouseLeave();
		void HandleMouseButtonClick();
		void HandleMouseButtonPress();
		void HandleMouseButtonRelease();
		void HandleSizeAllocate();

		Label::Ptr  m_label;
		float m_padding;
};

}
