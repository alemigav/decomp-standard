/* FUN_8004c21c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c21c  body 0x8004c21c..0x8004c49f  size 644 B
 * body sha256 d015732252c74a4e6925316a1f87d098f66ca865f951f7983f664b21c410f54e
 * provider record sha256 bff6248d473256fe305ce2598637ffc977887f61d705c2840b6c40de5564c72a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004c21c(int param_1,uint param_2,byte *param_3,ushort param_4)

{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  bVar2 = *param_3;
  puVar5 = DAT_8010aa88;
  if (bVar2 != 0xfe) {
    puVar3 = DAT_8010aa88 + 3;
    do {
      iVar4 = 0xe;
      if (bVar2 == 0) {
        if ((param_4 & 0x4000) == 0) {
          param_1 = param_1 + 0xe;
        }
        else {
          param_1 = param_1 + 8;
        }
        goto switchD_8004c2ac_caseD_f5;
      }
      switch(*param_3) {
      case 0xee:
        param_3 = param_3 + 1;
        *(byte *)((int)puVar3 + -3) = (*param_3 / 0x12) * '\x0e' + -0x2e;
        break;
      case 0xef:
        param_3 = param_3 + 1;
        *(byte *)((int)puVar3 + -3) = (*param_3 / 0x12) * '\x0e';
        break;
      case 0xf0:
        param_3 = param_3 + 1;
        *(byte *)((int)puVar3 + -3) = (*param_3 / 0x12) * '\x0e' + -0x3c;
        break;
      default:
        *(byte *)((int)puVar3 + -3) = (*param_3 / 0x12) * '\x0e' + '\x1c';
        if (((param_4 & 0x4000) != 0) && (iVar1 = (uint)*param_3 * 2, *param_3 < 0x57)) {
          param_1 = param_1 - (char)(&DAT_800f9ec0)[iVar1];
          iVar4 = (int)(char)(&DAT_800f9ec1)[iVar1] + (int)(char)(&DAT_800f9ec0)[iVar1];
        }
        break;
      case 0xf5:
        goto switchD_8004c2ac_caseD_f5;
      case 0xf6:
        param_1 = param_1 + 7;
        goto switchD_8004c2ac_caseD_f5;
      case 0xf7:
      case 0xfe:
        goto switchD_8004c2ac_caseD_f7;
      }
      *puVar5 = 0x64808080;
      puVar3[1] = 0xe000e;
      puVar3[-2] = param_2 | param_1 << 0x10;
      bVar2 = *param_3;
      puVar5 = puVar5 + 5;
      *(undefined1 *)((int)puVar3 + -9) = 0;
      *(ushort *)((int)puVar3 + -2) = (param_4 & 0xf0) << 3;
      *puVar3 = &DAT_8010b2bc;
      *(byte *)(puVar3 + -1) = (bVar2 % 0x12) * '\x0e';
      puVar3 = puVar3 + 5;
      if (puVar5 == (undefined4 *)&UNK_800ff688) break;
      param_1 = param_1 + iVar4;
switchD_8004c2ac_caseD_f5:
      param_3 = param_3 + 1;
      bVar2 = *param_3;
    } while (bVar2 != 0xfe);
  }
  if (DAT_8010aa88 != puVar5) {
    DAT_800df8b4 = FUN_80043868(DAT_800df8b4,DAT_8010aa88,puVar5);
  }
  DAT_8010aa88 = puVar5;
switchD_8004c2ac_caseD_f7:
  return;
}
