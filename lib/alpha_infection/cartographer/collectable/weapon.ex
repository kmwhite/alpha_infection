defmodule AlphaInfection.Cartographer.Collectable.KeyCard do
  @typedoc """
  """

  @required [:classification]
  @optional []

  @enforce_keys @required
  defstruct @required ++ @optional

  def use do
  end
end
