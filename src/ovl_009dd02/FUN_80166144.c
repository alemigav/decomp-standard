/* FUN_80166144
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166144  body 0x80166144..0x8016624b  size 264 B
 * body sha256 afcda2ee19d45f2c69f3c1ae1bc9e9924da45276aab11f36919308f13a28eeab
 * provider record sha256 e1eff2eb2ff826679c4a876888d38396d45ac9ece80a8d33f872bb03c292c23b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166144(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[0x7a] = 0x4001f00;
    func_0x800334c8();
    func_0x80089d54(param_1,param_2,param_3,0x40);
    *(undefined2 *)(param_1 + 0x7d) = 0x4a3;
  }
  else {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
    if (iVar2 != 0) {
      param_1[1] = 0x1000000;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *param_1 = *param_1 & 0xffffffbd;
    }
    func_0x80032b5c(param_1,0x800);
    sVar1 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar1 + *(short *)(param_1 + 0x78);
    if (0x739 < (short)(sVar1 + *(short *)(param_1 + 0x78))) {
      *param_1 = *param_1 & 0xffffffbd;
    }
  }
  return;
}
