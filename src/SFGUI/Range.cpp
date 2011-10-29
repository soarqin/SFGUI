#include <SFGUI/Range.hpp>

namespace sfg {

Range::Range() :
	Widget(),
	m_change_connection( 0 )
{
	SetAdjustment( Adjustment::Create() );
}

Adjustment::Ptr Range::GetAdjustment() const {
	return m_adjustment;
}

void Range::SetAdjustment( Adjustment::Ptr adjustment ) {
	m_adjustment = adjustment;

	// Connect change signal. This also disconnects the previous connection.
	m_change_connection = m_adjustment->OnChange.Connect( &Range::HandleAdjustmentChange, this );
}

float Range::GetValue() const {
	return m_adjustment->GetValue();
}

void Range::SetValue( float new_value ) {
	m_adjustment->SetValue( new_value );
}

void Range::SetIncrements( float minor_step, float major_step ) {
	m_adjustment->SetMinorStep( minor_step );
	m_adjustment->SetMajorStep( major_step );
}

void Range::SetRange( float min, float max ) {
	m_adjustment->SetLower( min );
	m_adjustment->SetUpper( max );
}

void Range::HandleAdjustmentChange() {
	Invalidate();
}

}
