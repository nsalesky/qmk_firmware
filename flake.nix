{
  description = "My custom QMK firmware";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        # For `nix build` and `nix run`
        # defaultPackage = naersk-lib.buildPackage {
        #   src = ./.;
        #
        #   nativeBuildInputs = with pkgs; [
        #     pkg-config
        #     gtk4
        #     libadwaita
        #   ];
        # };

        # For `nix develop`
        devShell = with pkgs; mkShell {
          buildInputs = [
            qmk
          ];
        };
      });
}
