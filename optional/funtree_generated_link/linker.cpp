
#if defined(_WINDOWS)
  #define PLUGIN_EXPORT __declspec(dllexport)
#else
  #define PLUGIN_EXPORT
#endif


PLUGIN_EXPORT bool linkFuntreeGenerated () {

  return true;
}
