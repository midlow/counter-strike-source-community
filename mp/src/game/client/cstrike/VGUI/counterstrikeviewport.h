//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef COUNTERSTRIKEVIEWPORT_H
#define COUNTERSTRIKEVIEWPORT_H

#include "cs_shareddefs.h"
#include "baseviewport.h"


using namespace vgui;

namespace vgui 
{
	class Panel;
	class Label;
	class CBitmapImagePanel;
}

class CCSTeamMenu;
class CCSClassMenu;
class CCSSpectatorGUI;
class CCSClientScoreBoard;
class CBuyMenu;
class CCSClientScoreBoardDialog;



//==============================================================================
class CounterStrikeViewport : public CBaseViewport
{

private:
	DECLARE_CLASS_SIMPLE( CounterStrikeViewport, CBaseViewport );

public:

#ifdef COMMUNITY_DLL
			CounterStrikeViewport();
	virtual ~CounterStrikeViewport();
#endif

	IViewPortPanel* CreatePanelByName(const char *szPanelName);
	void CreateDefaultPanels( void );
#ifdef COMMUNITY_DLL
	virtual void RemoveAllPanels( void );
#endif

	virtual void ApplySchemeSettings( vgui::IScheme *pScheme );
	virtual void Start( IGameUIFuncs *pGameUIFuncs, IGameEventManager2 * pGameEventManager );
		
	int GetDeathMessageStartHeight( void );

#ifdef COMMUNITY_DLL	
	void StartMainMenuVideo();
	void StopMainMenuVideo();
#endif

	virtual void ShowBackGround(bool bShow) 
	{
		m_pBackGround->SetVisible( false );	// CS:S menus paint their own backgrounds...
	}
	
#ifdef COMMUNITY_DLL
	virtual void OnScreenSizeChanged(int iOldWide, int iOldTall);
#endif

private:
	void CenterWindow( vgui::Frame *win );

#ifdef COMMUNITY_DLL	
	class CMainMenu* m_pMainMenuPanel;
#endif

};


#endif // COUNTERSTRIKEVIEWPORT_H
