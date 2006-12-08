# RGL-demo: subdivision surfaces
# author: Daniel Adler
# $Id: subdivision.r 491 2006-07-31 13:17:19Z dmurdoch $

rgl.demo.subdivision <- function()
{
  # setup environment
  rgl.clear("all")
  bg3d(color="gray")
  light3d()

  # generate basic mesh
  obj <- oh3d()

  part <- function( level, tx, ... )
  {
    shade3d( translate3d( obj, tx, 0, 0 )
    , color="gray30", front="lines",alpha=0.5,back="lines", override=TRUE
    )
    shade3d( translate3d( subdivision3d( obj, depth=level ), tx, 0, 0 )
    , override=TRUE, ... )
  }
  
  common <- c(alpha=0.5)
  
  part(0, -5.50, color="blue"   , common )
  part(1, -1.75, color="yellow" , common )
  part(2,  1.75, color="red"    , common )
  part(3,  5.50, color="green"  , common )

}

rgl.open()
rgl.demo.subdivision()

