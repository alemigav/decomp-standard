/* FUN_8003011c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003011c  body 0x8003011c..0x8003025b  size 320 B
 * body sha256 36f719f5bec746f7cd74c70d51512c4a3716c918f5139fcd4187a65becc57848
 * provider record sha256 79a0c1255df44105af31e6a5dfa15d9a0bbb52c4565ab42811892491b635f5a8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8003011c(int *param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = param_3 * 0x80;
  uVar8 = 0x3b9ac9f0 / uVar6;
  if (uVar6 == 0) {
    trap(0x1c00);
  }
  iVar7 = param_1[1];
  if (uVar8 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x3e;
    (**(code **)*param_1)();
  }
  uVar4 = param_4;
  if ((int)uVar8 < (int)param_4) {
    uVar4 = uVar8;
  }
  *(uint *)(iVar7 + 0x4c) = uVar4;
  iVar7 = FUN_8002fd38(param_1,param_2,param_4 << 2);
  uVar8 = 0;
  if (param_4 != 0) {
    uVar5 = param_4;
    while( true ) {
      uVar3 = uVar5;
      if (uVar4 < uVar5) {
        uVar3 = uVar4;
      }
      iVar1 = FUN_8002fef4(param_1,param_2,uVar3 * param_3 * 0x80);
      if (uVar3 != 0) {
        piVar2 = (int *)(uVar8 * 4 + iVar7);
        uVar4 = uVar3;
        do {
          *piVar2 = iVar1;
          piVar2 = piVar2 + 1;
          uVar8 = uVar8 + 1;
          uVar4 = uVar4 - 1;
          iVar1 = iVar1 + uVar6;
        } while (uVar4 != 0);
      }
      if (param_4 <= uVar8) break;
      uVar5 = param_4 - uVar8;
      uVar4 = uVar3;
    }
  }
  return iVar7;
}
