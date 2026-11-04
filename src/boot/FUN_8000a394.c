/* FUN_8000a394
 * image   boot (boot), base 0x80000480
 * address 0x8000a394  body 0x8000a394..0x8000a66b  size 728 B
 * body sha256 5ad9c894800123adc9c611fea228f01f167051fa572b885cb5a791fbcba93c2e
 * provider record sha256 e8408260bb3fbf45ed09425ef83cb75344a83d6b92acd6e937c46c86175d3334
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000a394(int param_1,int param_2,char param_3,byte param_4)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  
  if (*(char *)(param_1 + 0x65) != '\0') {
    *(undefined1 *)(param_1 + 0x65) = 0;
    iVar2 = FUN_8000a66c();
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  iVar2 = 1;
  if (param_4 == 0) {
    iVar2 = *(int *)(param_1 + 0x60);
  }
  if (param_3 == '\x01') {
    pcVar5 = (char *)(iVar2 * 2 + param_2);
    iVar4 = 0;
    iVar6 = (0x80 - iVar2) * 2;
    cVar3 = '\0';
    if (0 < iVar6) {
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        iVar4 = iVar4 + 1;
        cVar3 = cVar3 + cVar1;
      } while (iVar4 < iVar6);
    }
    *(char *)(param_2 + 1) = cVar3;
  }
  iVar6 = 0;
  iVar7 = (uint)param_4 * 8;
  iVar4 = 0;
  while( true ) {
    iVar4 = param_2 + iVar4;
    if (param_3 == '\x01') {
      FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                   *(int *)(param_1 + 0x54) + iVar7 + iVar6 & 0xffff,iVar4,0);
      iVar4 = FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(int *)(param_1 + 0x58) + iVar7 + iVar6 & 0xffff,iVar4,0);
    }
    else {
      iVar4 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(int *)(param_1 + 0x54) + iVar7 + iVar6 & 0xffff,iVar4);
    }
    iVar6 = iVar6 + 1;
    if (iVar4 != 0) break;
    iVar4 = iVar6 * 0x20;
    if (7 < iVar6) {
      iVar4 = 0;
      if (param_3 == '\0') {
        cVar3 = '\0';
        pcVar5 = (char *)(iVar2 * 2 + param_2);
        iVar4 = (0x80 - iVar2) * 2;
        iVar2 = 0;
        if (0 < iVar4) {
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
            iVar2 = iVar2 + 1;
            cVar3 = cVar3 + cVar1;
          } while (iVar2 < iVar4);
        }
        iVar2 = 0;
        if (cVar3 == *(char *)(param_2 + 1)) {
          do {
            FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(int *)(param_1 + 0x58) + (uint)param_4 * 8 + iVar2 & 0xffff,param_2,0);
            iVar2 = iVar2 + 1;
            iVar4 = 0;
            param_2 = param_2 + 0x20;
          } while (iVar2 < 8);
        }
        else {
          iVar4 = param_2;
          do {
            FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(int *)(param_1 + 0x58) + (uint)param_4 * 8 + iVar2 & 0xffff,iVar4);
            iVar2 = iVar2 + 1;
            iVar4 = iVar4 + 0x20;
          } while (iVar2 < 8);
          iVar4 = 3;
          if (cVar3 == *(char *)(param_2 + 1)) {
            iVar2 = 0;
            do {
              FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(int *)(param_1 + 0x54) + (uint)param_4 * 8 + iVar2 & 0xffff,param_2,0);
              iVar2 = iVar2 + 1;
              iVar4 = 0;
              param_2 = param_2 + 0x20;
            } while (iVar2 < 8);
          }
        }
      }
      return iVar4;
    }
  }
  return iVar4;
}
