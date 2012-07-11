/*
 * From newlib ==> libc/sys/sysnecv850/crt1.c
 *
 * Obtained newlib 29 May 2012
 */
void __main ()
{
  static int initialized;
  if (! initialized)
    {
      typedef void (*pfunc) ();
      extern pfunc __ctors[];
      extern pfunc __ctors_end[];
      pfunc *p;

      initialized = 1;
      for (p = __ctors_end; p > __ctors; )
	(*--p) ();

    }
}
