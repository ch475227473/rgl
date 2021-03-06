\name{rgl-package}
\title{3D visualization device system}
\alias{rgl-package}
\alias{rgl}
\description{
  3D real-time rendering system.
}
\details{
  RGL is a 3D real-time rendering system for R.
  Multiple windows are managed at a time. Windows
  may be divided into \dQuote{subscenes}, where one has the current focus
  that receives instructions from the R command-line. 
  The device design is oriented towards the R device metaphor. If you send
  scene management instructions, and there's no device open, it will be opened
  automatically.
  Opened devices automatically get the current device focus. The focus may be
  changed by using \code{\link{rgl.set}()} or \code{\link{useSubscene3d}()}.
  
  \pkg{rgl} provides medium to high level functions for 3D interactive graphics, including
  functions modelled on base graphics (\code{\link{plot3d}()}, etc.) as well as functions for 
  constructing geometric objects (\code{\link{cube3d}()}, etc.).  Output
  may be on screen using OpenGL, or to various standard 3D file formats including 
  WebGL, PLY, OBJ, STL as well as 2D image formats, including PNG, Postscript, SVG, PGF.
  
  The \code{\link{open3d}()} function attempts to open a new RGL window,
  using default settings specified by the user.
  
  \pkg{rgl} also includes a lower level interface which is described
  in the \link{rgl.open} help topic.  We recommend that you avoid mixing
  \code{rgl.*} and \code{*3d} calls.

  See the first example below to display the ChangeLog.
}
\seealso{\link{r3d} for a description of the \code{*3d} interface;
\code{\link{par3d}} for a description of scene properties and the rendering
pipeline.}
\examples{
file.show(system.file("NEWS", package = "rgl"))
example(surface3d)
example(plot3d)
}
\keyword{dynamic}
