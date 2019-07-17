import { Component, OnInit, Input, ElementRef, NgZone } from '@angular/core';

import { SubTask } from '../model/subtask';

@Component({
  selector: 'app-subtask',
  templateUrl: './subtask.component.html',
  styleUrls: ['./subtask.component.css']
})
export class SubtaskComponent implements OnInit {
  @Input()
  subTask: SubTask;
  editingsubTask = false;
  currentTitle: string;
  zone: NgZone;
  constructor(private el: ElementRef) {}

  ngOnInit() {}
  blurOnEnter(event) {
    if (event.keyCode === 13) {
      event.target.blur();
    } else if (event.keyCode === 27) {
      this.subTask.title = this.currentTitle;
      this.editingsubTask = false;
    }
  }

  editsubTask() {
    this.editingsubTask = true;
    this.currentTitle = this.subTask.title;

    const textArea = this.el.nativeElement.getElementsByTagName('textarea')[0];

    setTimeout(() => {
      textArea.focus();
    }, 0);
  }

  updatesubTask() {
    if (!this.subTask.title || this.subTask.title.trim() === '') {
      this.subTask.title = this.currentTitle;
    }

    // this._subTaskService.put(this.subTask).then(res => {
    // this._ws.updatesubTask(this.subTask.boardId, this.subTask);
    // });
    this.editingsubTask = false;
  }
}
