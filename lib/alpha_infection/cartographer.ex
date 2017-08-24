defmodule AlphaInfection.Cartographer do
  @moduledoc """
  The Cartographer is responsible for the management of the game map.
  All movement and placement of COLLECTABLES happens within the
  Cartographer.

  The map is implemented as a graph struture. Each node represents a
  given ROOM on the map.
  """

  @name __MODULE__

  @doc "Initiate the creation of a populated map for gameplay"
  def start_link do
    Agent.start_link(fn -> initial_state end, name: Numbers)
  end

  def move(player_pid, {room_class, room_wing, room_id}) do
  end

  def initial_state do

  end

end
