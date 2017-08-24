defmodule AlphaInfection.Cartographer.Room do
  @typedoc """
  A Structure to Describe the Room on the FloorPlan
  """

  # AccessLevel: One of :engineering, :medical, :science
  # Wing: Takes a cardinal direction [:north, :south, :east, :west]
  # Identifier: tuple of {floor, section, id}
  @required [:access_level, :wing, :identifier]
  # Collectables: An list of AlphaInfection.Cartographer.Collectable
  @optional [:collectables]

  @enforce_keys @required
  defstruct @required ++ @optional

end
