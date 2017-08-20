# AlphaInfection

Alpha Infection is a multiplayer game where players attempt to join and
stop a rampant computer virus from taking over a space station and driving
it directly into the Earth.

<!-- vim-markdown-toc GFM -->
* [Gameplay and Rules](#gameplay-and-rules)
* [Servers](#servers)
* [Clients](#clients)
* [Installation](#installation)
* [LICENSE](#license)

<!-- vim-markdown-toc -->

## Gameplay and Rules
Currently, they're being developed, but baseline is available in [NOTES](docs/NOTES)

## Servers
This Project provides the Server component of the system. It will have to probably implement
a public interface for client communication. While entirely doable from something like an
HTTP service, it would be a fun oppotunity to use a Protobuf.

## Clients
These are going to need implementation, but if done right, they can allow overlap between
differing clients so that where you play from doesn't matter.

## Installation
If [available in Hex](https://hex.pm/docs/publish), the package can be installed
by adding `alpha_infection` to your list of dependencies in `mix.exs`:

```elixir
def deps do
  [{:alpha_infection, "~> 0.1.0"}]
end
```

Documentation can be generated with [ExDoc](https://github.com/elixir-lang/ex_doc)
and published on [HexDocs](https://hexdocs.pm). Once published, the docs can
be found at [https://hexdocs.pm/alpha_infection](https://hexdocs.pm/alpha_infection).

## LICENSE

AlphaInfection's code is licensed under the [BSD (2-Clause) License](docs/LICENSE)
