/* FUN_8000cde0
 * image   boot (boot), base 0x80000480
 * address 0x8000cde0  body 0x8000cde0..0x8000cdef  size 16 B
 * body sha256 59cc9514a446102126f66c3f082c35bd6e025ec79b48c8b39cf3f9e10e172bc4
 * provider record sha256 225996fe1e9749198a698aca5e9e9203e562db8039a51f23048032e55cee5e9c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000cde0(undefined4 param_1)

{
  setCopReg(0,Status,param_1);
  return;
}
