/* FUN_8015ba60
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015ba60  body 0x8015ba60..0x8015bac7  size 104 B
 * body sha256 ee46c9e0aa32f9d010f3ede8f087098317e2cf153d11e94e4cb240aeda19a86b
 * provider record sha256 15ed93a323e981980af8f61974a33dd9e74b2c72eddf09fb13c10a99bfe7ad43
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8015ba60(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  FUN_8015fbb8();
  uVar2 = 0;
  if (DAT_80160c21 == '\x01') {
    FUN_8015f298(DAT_80160c22);
    uVar2 = 0x1b;
    uVar1 = 1;
  }
  else {
    uVar1 = DAT_80160c22;
  }
  FUN_8015e384(uVar1,uVar1,uVar2,0);
  return;
}
