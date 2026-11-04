/* FUN_80000f60
 * image   boot (boot), base 0x80000480
 * address 0x80000f60  body 0x80000f60..0x80001053  size 244 B
 * body sha256 3a752f2c523c01b649c6f79b0493cd0cab2282cb700d773a1cc722bc404bc0b1
 * provider record sha256 87800d0e104bd10700fddd0b553b58bbc89de2aade3acfb119ac713a903bc00a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80000f60(void)

{
  int iVar1;
  
  iVar1 = FUN_80000f50(&DAT_80012948);
  _DAT_80012950 = iVar1;
  *(undefined2 *)(iVar1 + 0x10) = 4;
  setCopReg(0,Status,*(uint *)(iVar1 + 0x118) & 0xffff00ff |
                     *(uint *)(iVar1 + 0x118) & 0xff00 & _DAT_800128d0 & 0xff00);
  if ((_DAT_80012140 != 0) && (_DAT_80012140 < _DAT_80012144)) {
    *(int *)(_DAT_80012140 + 0xc) = iVar1;
    *(undefined4 *)(_DAT_80012140 + 8) = 2;
    *(undefined4 *)(_DAT_80012140 + 4) = Count;
    _DAT_80012140 = _DAT_80012140 + 0x10;
  }
  if ((*(int *)(iVar1 + 0x18) == 0) || ((*(uint *)(iVar1 + 0x118) & 0x4000000) == 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
