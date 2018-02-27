# Inbox

<div class="code-swift">
NearManager.shared.inbox { (items, error) in
    if let items = items {
        // New items available, show them in your UI or use the Inbox UI available in Near UI Bindings
    }
}
</div>
<div class="code-objc">
[[NITManager defaultManager] inboxWithCompletion:^(NSArray<NITInboxItem *>* _Nullable items, NSError* _Nullable error) {
    if (items) {
        // New items available, show them in your UI or use the Inbox UI available in Near UI Bindings
    }
}];
</div>
