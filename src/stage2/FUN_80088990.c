/* FUN_80088990
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088990  body 0x80088990..0x80088b5b  size 460 B
 * body sha256 1da5299dfb2cd4d8618ef97094de73180578dab05c699372c6f09e1aece5b3f2
 * provider record sha256 8cd090b5128cc0d956eea52877eafd4a4327d4cfecd647de40a127a607c29721
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088990(int param_1,uint *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  char cVar4;
  int local_48;
  int local_44;
  int local_40;
  undefined1 auStack_38 [20];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((param_3 & 0x2000000) == 0) {
    FUN_80040e58(param_1 + 100,param_1 + 0x14);
  }
  else {
    FUN_80040e58(param_1 + 100,auStack_38);
    if ((param_3 & 0x1000000) == 0) {
      FUN_8004226c(*(undefined4 *)(param_1 + 0x70),auStack_38,param_1 + 0x14);
    }
    else {
      local_24 = *(undefined4 *)(param_1 + 0x28);
      local_20 = *(undefined4 *)(param_1 + 0x2c);
      local_1c = *(undefined4 *)(param_1 + 0x30);
      FUN_800424ec(*(undefined4 *)(param_1 + 0x70),auStack_38,param_1 + 0x14);
    }
  }
  if ((param_3 & 0x800) != 0) {
    local_48 = (int)*(short *)(param_1 + 0x212);
    local_44 = (int)*(short *)(param_1 + 0x212);
    local_40 = (int)*(short *)(param_1 + 0x212);
    FUN_80040d2c(param_1 + 0x14,&local_48);
  }
  FUN_80083200(param_1 + 0x78,param_2 + 0x13);
  cVar4 = *(char *)(param_1 + 0x1a3);
  iVar1 = FUN_80083d2c(param_4,DAT_800df940);
  if (iVar1 == 0) {
    puVar3 = param_2 + 0xe;
  }
  else {
    puVar3 = param_2 + 0xe;
    if ((param_3 & 0x80000) == 0) {
      do {
        if ((*param_2 & 1) != 0) {
          FUN_80088b5c(param_1,param_2,*param_2,param_2 + 0xe);
        }
        cVar4 = cVar4 + -1;
        param_2 = param_2 + 0x5e;
      } while (cVar4 != '\0');
      return;
    }
  }
  do {
    uVar2 = *param_2;
    if ((uVar2 & 0x9000) == 0) {
      if ((uVar2 & 1) != 0) {
        FUN_80088e34(param_1,param_2,uVar2,puVar3);
      }
    }
    else if ((uVar2 & 1) != 0) {
      FUN_80088b5c(param_1,param_2,uVar2,puVar3);
    }
    puVar3 = puVar3 + 0x5e;
    cVar4 = cVar4 + -1;
    param_2 = param_2 + 0x5e;
  } while (cVar4 != '\0');
  return;
}
