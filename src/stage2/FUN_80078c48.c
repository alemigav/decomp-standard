/* FUN_80078c48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078c48  body 0x80078c48..0x80078ee3  size 668 B
 * body sha256 a28573cc9f662984d9c5295ad90e9ee3e86595a54a5da314000bab92919a228f
 * provider record sha256 2f004fff50556e040e7f229f1e72da2bbd4403e5cad08c5a53af2049570e8ce1
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80078c48(short param_1,char param_2,undefined4 param_3,short param_4)

{
  char cVar2;
  undefined4 uVar1;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = param_1 * 0x3c;
  if ((&DAT_8011a3a4)[iVar4] != '\0') {
    iVar6 = 0;
    if ('\0' < (char)(&DAT_8011a3a4)[iVar4]) {
      iVar5 = iVar4;
      iVar7 = iVar4;
      iVar8 = iVar4;
      do {
        if (*(int *)((int)&DAT_8011a390 + iVar5) == 0) break;
        if ((*(int *)((int)&DAT_8011a380 + iVar5) != -1) && (cVar2 = FUN_800a21a8(), cVar2 != '\0'))
        {
          FUN_800a1f40(*(undefined4 *)((int)&DAT_8011a380 + iVar5));
        }
        uVar1 = FUN_800a8bc8(*(undefined2 *)(&DAT_8011a3a6 + iVar4),
                             *(undefined2 *)(&DAT_8011a3a8 + iVar8),
                             *(undefined4 *)((int)&DAT_8011a390 + iVar5),0);
        *(undefined4 *)((int)&DAT_8011a380 + iVar5) = uVar1;
        (&DAT_8011a3a4)[iVar4] = 0xfe;
        if (param_4 == 0) {
          (&DAT_8011a3a0)[iVar7] = 0x7f;
        }
        else {
          (&DAT_8011a3a0)[iVar7] = 0;
        }
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 4;
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + 2;
      } while (iVar6 < 4);
      FUN_80079260((int)param_1);
    }
    iVar4 = 0;
    if (param_2 == '\0') {
      iVar6 = param_1 * 0x3c;
      do {
        if (*(int *)((int)&DAT_8011a390 + iVar6) == 0) break;
        iVar4 = iVar4 + 1;
        if (((&DAT_8011a3a4)[param_1 * 0x3c] == -2) &&
           (cVar2 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar6)), cVar2 != '\0')) {
          FUN_800a1f84(*(undefined4 *)((int)&DAT_8011a380 + iVar6));
        }
        iVar6 = iVar6 + 4;
      } while (iVar4 < 4);
      uVar3 = 0xff;
    }
    else {
      if (param_2 != '\x01') {
        return;
      }
      iVar6 = param_1 * 0x3c;
      do {
        if (*(int *)((int)&DAT_8011a390 + iVar6) == 0) break;
        iVar4 = iVar4 + 1;
        if (((&DAT_8011a3a4)[param_1 * 0x3c] == -1) &&
           (cVar2 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar6)), cVar2 != '\0')) {
          FUN_800a1fc8(*(undefined4 *)((int)&DAT_8011a380 + iVar6));
        }
        iVar6 = iVar6 + 4;
      } while (iVar4 < 4);
      uVar3 = 0xfe;
    }
    (&DAT_8011a3a4)[param_1 * 0x3c] = uVar3;
  }
  return;
}
