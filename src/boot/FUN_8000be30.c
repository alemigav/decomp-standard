/* FUN_8000be30
 * image   boot (boot), base 0x80000480
 * address 0x8000be30  body 0x8000be30..0x8000be4f  size 32 B
 * body sha256 f2fc943b6d1aafa2ef3895cfdfb5cf2f8963a5e24189afb4516ad411c6063e85
 * provider record sha256 f6a31d3f9bfe0f7991fe34c1cbe68ea77f720ad6c213ef7429dafda2bd6fe6f0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000be30(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (_DAT_800128f0 != 0) {
    uVar1 = _DAT_800128f8;
  }
  return uVar1;
}
