/* FUN_80162be4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162be4  body 0x80162be4..0x80162c87  size 164 B
 * body sha256 ed55c7e5097dc9c5b6cb088cb147b0c8498403b207452678a5c6ea9c18c76861
 * provider record sha256 8ee621faf56b932c775d33f2209644bf4db5aa024ee19db88ef5883ba6d3a970
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162be4(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    func_0x80077d18(10,param_1);
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfe;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if (sVar1 == 1) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
