/* FUN_80162a18
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162a18  body 0x80162a18..0x80162bc3  size 428 B
 * body sha256 a80e276d06d886d93b0d8bb7ba57e25ee1e069cbba66e9216d06b637976c209b
 * provider record sha256 b40369549af0c3419ae32317b80a7656117d15bd8b5bdfcc6257216f54b39d6e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162a18(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6)

{
  char cVar3;
  uint uVar1;
  int iVar2;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar4 = 0x24;
  if ((param_6 & 2) != 0) {
    cVar3 = func_0x80033144(param_1,&DAT_800e1130);
    if (cVar3 != '\0') {
      iVar5 = 0x12;
    }
    uVar4 = 0x12;
  }
  if ((param_6 & 1) != 0) {
    uVar4 = 6;
    iVar5 = iVar5 + ((uint)*(byte *)(param_1 + 0x26e) % 3) * 6;
  }
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      uVar1 = func_0x80033604();
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      iVar2 = (iVar5 + (uVar1 & 0xff) % uVar4) * 0xc;
      if ((param_6 & 4) == 0) {
        FUN_801628f0(param_1,param_3,param_4,param_5,
                     (int)*(short *)(param_1 + 0x66) + (int)*(short *)(&DAT_80166136 + iVar2),
                     *(undefined4 *)(&DAT_80166138 + iVar2),&UNK_80166130 + iVar2);
      }
      else {
        FUN_801629c4(param_1,param_3,param_4,param_5,
                     (int)*(short *)(param_1 + 0x66) + (int)*(short *)(&DAT_80166136 + iVar2),
                     *(undefined4 *)(&DAT_80166138 + iVar2),&UNK_80166130 + iVar2);
      }
    } while (param_2 != 0);
  }
  return;
}
