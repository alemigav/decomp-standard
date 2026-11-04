/* FUN_8006b3dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b3dc  body 0x8006b3dc..0x8006b6b3  size 728 B
 * body sha256 46563cda9159794da952c549f4f0557c27f30b76d7a95c29a436a59a1632da17
 * provider record sha256 eabd9347d644a280f26edd39b6b4892bf38a6960d13fc95b0093493cd07aa14d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006b3dc(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  if (param_2 == 3) {
    FUN_8006b3dc(param_1,1);
    FUN_8006b3dc(param_1,2,param_3);
  }
  if (param_3 == 1) {
    iVar1 = param_1 * 0xa8 + param_2 * 0x38;
    if ((&DAT_80113488)[iVar1] == '\x01') {
      (&DAT_80113488)[iVar1] = '\x02';
    }
    lVar4 = func_0x80007030();
    uVar5 = func_0x80006100((int)((ulonglong)(lVar4 << 6) >> 0x20),(int)(lVar4 << 6),0,3000);
    *(undefined8 *)(&DAT_80113490 + iVar1) = uVar5;
  }
  else if (param_3 < 2) {
    if (param_3 == 0) {
      (&DAT_80113488)[param_1 * 0xa8 + param_2 * 0x38] = 1;
    }
  }
  else if (param_3 == 2) {
    lVar4 = func_0x80007030();
    iVar1 = param_1 * 0xa8 + param_2 * 0x38;
    uVar5 = func_0x80006100((int)((ulonglong)(lVar4 << 6) >> 0x20),(int)(lVar4 << 6),0,3000);
    *(undefined8 *)(&DAT_80113498 + iVar1) = uVar5;
    uVar2 = FUN_8006b364(*(undefined4 *)(&DAT_80113494 + iVar1),
                         *(undefined4 *)(&DAT_8011349c + iVar1));
    uVar3 = (int)uVar2 >> 0x1f;
    if ((&DAT_80113488)[iVar1] == '\x02') {
      *(uint *)(&DAT_801134a0 + iVar1) = uVar3;
      *(uint *)(&DAT_801134a4 + iVar1) = uVar2;
      *(undefined4 *)(&DAT_801134b8 + iVar1) = 1;
      *(uint *)(&DAT_801134a8 + iVar1) = uVar3;
      *(uint *)(&DAT_801134ac + iVar1) = uVar2;
      *(uint *)(&DAT_801134b0 + iVar1) = uVar3;
      *(uint *)(&DAT_801134b4 + iVar1) = uVar2;
      (&DAT_80113488)[iVar1] = '\0';
    }
    else if (*(uint *)(&DAT_801134b8 + iVar1) < DAT_801137d0) {
      *(uint *)(&DAT_801134a0 + iVar1) =
           *(int *)(&DAT_801134a0 + iVar1) + uVar3 +
           (uint)(*(int *)(&DAT_801134a4 + iVar1) + uVar2 < uVar2);
      *(uint *)(&DAT_801134a4 + iVar1) = *(int *)(&DAT_801134a4 + iVar1) + uVar2;
      if ((*(uint *)(&DAT_801134b0 + iVar1) < uVar3) ||
         ((uVar3 == *(uint *)(&DAT_801134b0 + iVar1) && (*(uint *)(&DAT_801134b4 + iVar1) < uVar2)))
         ) {
        *(uint *)(&DAT_801134b0 + iVar1) = uVar3;
        *(uint *)(&DAT_801134b4 + iVar1) = uVar2;
      }
      iVar1 = param_1 * 0xa8 + param_2 * 0x38;
      if ((uVar3 < *(uint *)(&DAT_801134a8 + iVar1)) ||
         ((*(uint *)(&DAT_801134a8 + iVar1) == uVar3 && (uVar2 < *(uint *)(&DAT_801134ac + iVar1))))
         ) {
        *(uint *)(&DAT_801134a8 + iVar1) = uVar3;
        *(uint *)(&DAT_801134ac + iVar1) = uVar2;
      }
      iVar1 = param_1 * 0xa8 + param_2 * 0x38;
      *(int *)(&DAT_801134b8 + iVar1) = *(int *)(&DAT_801134b8 + iVar1) + 1;
    }
  }
  return;
}
