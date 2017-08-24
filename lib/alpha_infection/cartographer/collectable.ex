defmodule AlphaInfection.Cartographer.Collectable do
  @typedoc '''
  '''
  @type __MODULE__ :: {}

  # One of:
  #   * Health Pack
  #   * Key Card (one of :engineering, :medical, :science)
  #   * Laser Mic (:engineering COLLECTABLE)
  #   * Sonic Dampener (:medical COLLECTABLE)
  #   * Guidance Chip (:science COLLECTABLE)
  @required [:access_level, :wing, :identifier]
  @optional [:collectables]

  def use do
  end
end
