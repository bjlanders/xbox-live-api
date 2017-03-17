//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
#pragma once
#include "xsapi/tournaments.h"
#include "TournamentState_WinRT.h"
#include "TeamState_WinRT.h"

NAMESPACE_MICROSOFT_XBOX_SERVICES_TOURNAMENTS_BEGIN

/// <summary>
/// Represents 
/// </summary>
public ref class Tournament sealed
{
public:
    /// <summary>
    /// The ID of the tournament. It is an opaque string specified by the tournament organizer.
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(Id, id);

    /// <summary>
    /// The organizer of this tournament.
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(OrganizerId, organizer_id);

    /// <summary>
    /// A string representing the friendly name of the organizer
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(OrganizerName, organizer_name);

    /// <summary>
    /// A friendly name for the tournament, intended for display.
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(Name, name);

    /// <summary>
    /// An additional, longer description of the tournament, intended for display.
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(Description, description);

    /// <summary>
    /// A string representing the friendly name of the game mode
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(GameMode, game_mode);

    /// <summary>
    /// A string representing the style of the tournament, such as "Single Elimination" or "Round Robin"
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(TournamentStyle, tournament_style);

    /// <summary>
    /// True when registration is open.
    /// </summary>
    DEFINE_PROP_GET_OBJ(IsRegistrationOpen, is_registration_open, bool);

    /// <summary>
    /// True when check-in is open. 
    /// </summary>
    DEFINE_PROP_GET_OBJ(IsCheckinOpen, is_checkin_open, bool);

    /// <summary>
    /// True when play is open.
    /// </summary>
    DEFINE_PROP_GET_OBJ(IsPlayingOpen, is_playing_open, bool);

    /// <summary>
    /// True if the tournament has a prize. False otherwise.
    /// </summary>
    DEFINE_PROP_GET_OBJ(HasPrize, has_prize, bool);

    /// <summary>
    /// A flag indicating whether the tournament is currently paused.
    /// </summary>
    DEFINE_PROP_GET_OBJ(IsPaused, is_paused, bool);

    /// <summary>
    /// The min number of players required in a team.
    /// </summary>
    DEFINE_PROP_GET_OBJ(MinTeamSize, min_team_size, uint32);

    /// <summary>
    /// The max number of players that can play on a team.
    /// </summary>
    DEFINE_PROP_GET_OBJ(MaxTeamSize, max_team_size, uint32);

    /// <summary>
    /// The number of teams registered for the tournament, not including waitlisted teams.
    /// </summary>
    DEFINE_PROP_GET_OBJ(TeamsRegisteredCount, teams_registered_count, uint32);

    /// <summary>
    /// This is the minimum number of registered teams. This does not include waitlisted teams.
    /// </summary>
    DEFINE_PROP_GET_OBJ(MinTeamsRegistered, min_teams_registered, uint32);

    /// <summary>
    /// This is the maximum number of registered teams. This does not include waitlisted teams.
    /// </summary>
    DEFINE_PROP_GET_OBJ(MaxTeamsRegistered, max_teams_registered, uint32);

    /// <summary>
    /// The current state of the tournament. Tournaments are Active by default. 
    /// Organizers can set the tournament to Canceled or Completed by explicitly updating the tournament.
    /// </summary>
    DEFINE_PROP_GET_ENUM_OBJ(TournamentState, tournament_state, Microsoft::Xbox::Services::Tournaments::TournamentState);

    /// <summary>
    /// The start time of registration. Must be before checkinStart.
    /// </summary>
    DEFINE_PROP_GET_DATETIME_OBJ(RegistrationStartTime, registration_start_time);

    /// <summary>
    /// The end time of registration. Must be before checkinStart.
    /// </summary>
    DEFINE_PROP_GET_DATETIME_OBJ(RegistrationEndTime, registration_end_time);

    /// <summary>
    /// The start time of checkin. Must be before playingStart.
    /// </summary>
    DEFINE_PROP_GET_DATETIME_OBJ(CheckinStartTime, checkin_start_time);

    /// <summary>
    /// The end time of checkin. Must be before playingStart.
    /// </summary>
    DEFINE_PROP_GET_DATETIME_OBJ(CheckinEndTime, checkin_end_time);

    /// <summary>
    /// The time the tournament begins.
    /// </summary>
    DEFINE_PROP_GET_DATETIME_OBJ(PlayingStartTime, playing_start_time);

    /// <summary>
    /// The time the tournament ends.
    /// </summary>
    DEFINE_PROP_GET_DATETIME_OBJ(PlayingEndTime, playing_end_time);

    /// <summary>
    /// The datetime that this tournament has reached either the Canceled or Completed state. 
    /// This is set automatically when a tournament is updated to be Canceled or Complete. 
    /// </summary>
    DEFINE_PROP_GET_DATETIME_OBJ(EndTime, end_time);

    /// <summary>
    /// The ID of the team. It is an opaque string specified by the tournament organizer.
    /// </summary>
    DEFINE_PROP_GET_STR_OBJ(TeamId, team_id);

    /// <summary>
    /// The state of the team.
    /// </summary>
    DEFINE_PROP_GET_ENUM_OBJ(TeamState, team_state, Microsoft::Xbox::Services::Tournaments::TeamState);

    /// <summary>
    /// The team's final rank within the tournament, if it is available. If missing, the rank is not available.
    /// </summary>
    DEFINE_PROP_GET_OBJ(TeamRanking, team_ranking, uint64);

internal:
    Tournament(
        _In_ xbox::services::tournaments::tournament cppObj
        );

    const xbox::services::tournaments::tournament& GetCppObj() const;
private:
    xbox::services::tournaments::tournament m_cppObj;
};

NAMESPACE_MICROSOFT_XBOX_SERVICES_TOURNAMENTS_END
