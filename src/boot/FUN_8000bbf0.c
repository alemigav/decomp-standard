/* FUN_8000bbf0
 * image   boot (boot), base 0x80000480
 * address 0x8000bbf0  body 0x8000bbf0..0x8000bd7f  size 400 B
 * body sha256 c39338699f8bdbf636451b1fe9f9d0b98774eec89a25b8d3b999471d405bced6
 * provider record sha256 c519abb01189817dc2b5e61adf43935ea69910e2d48bc7a77b718d6770d07fb5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000bbf0(int param_1,short param_2,int param_3,char *param_4,char *param_5,int *param_6)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int local_50;
  short local_4c;
  char local_44 [4];
  char local_40 [24];
  
  iVar3 = FUN_8000a2d0();
  iVar4 = 2;
  if (iVar3 != 2) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x50)) {
      do {
        iVar4 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                             *(int *)(param_1 + 0x5c) + iVar3 & 0xffff,&local_50);
        if (iVar4 != 0) {
          return iVar4;
        }
        if ((local_4c == param_2) && (local_50 == param_3)) {
          bVar2 = false;
          if (param_4 != (char *)0x0) {
            iVar4 = 0;
            pcVar5 = local_40;
            pcVar6 = param_4;
            do {
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
              if (*pcVar5 != cVar1) {
                bVar2 = true;
                break;
              }
              iVar4 = iVar4 + 1;
              pcVar5 = pcVar5 + 1;
            } while (iVar4 < 0x10);
          }
          if (param_5 != (char *)0x0 && !bVar2) {
            iVar4 = 0;
            pcVar5 = local_44;
            pcVar6 = param_5;
            do {
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
              if (*pcVar5 != cVar1) {
                bVar2 = true;
                break;
              }
              iVar4 = iVar4 + 1;
              pcVar5 = pcVar5 + 1;
            } while (iVar4 < 4);
          }
          if (!bVar2) {
            *param_6 = iVar3;
            return 0;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x50));
    }
    *param_6 = -1;
    iVar4 = 5;
  }
  return iVar4;
}
