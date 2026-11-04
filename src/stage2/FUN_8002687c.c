/* FUN_8002687c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002687c  body 0x8002687c..0x800268bb  size 64 B
 * body sha256 d577e3dfd4a355ce9815dba778d4824a54fcc40b3ad65f86c4b3fb2b5becea4e
 * provider record sha256 cb44402ae8f9104a6fc8bd490bba12c4391b79009d8f641f719932a71114cda1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002687c(void)

{
  undefined4 uVar1;
  
  if (DAT_800c56f4 == '\0') {
    uVar1 = DAT_8010b6e4;
  }
  else {
    uVar1 = DAT_8010b6e0;
  }
  FUN_8006bf48(uVar1);
  return;
}
